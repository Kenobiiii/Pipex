/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:23:40 by paromero          #+#    #+#             */
/*   Updated: 2024/04/23 10:10:03 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"

char	*find_command_path(char *cmd)
{
	char	*path;
	char	**path_dirs;
	char	*cmd_path;
	int		i;

	i = 0;
	path = getenv("PATH");
	path_dirs = ft_split(path, ':');
	while (path_dirs[i])
	{
		cmd_path = ft_strjoin(path_dirs[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		i++;
	}
	return (NULL);
}

void	execute_command(char **cmd)
{
	char	*cmd_path;

	cmd_path = find_command_path(cmd[0]);
	if (!cmd_path)
	{
		perror("No se ha encontrado el comando");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (execve(cmd_path, cmd, NULL) == -1)
		{
			perror("No se ha podido ejecutar el comando");
			exit(EXIT_FAILURE);
		}
	}
}

void	child_process(int fd[], char **cmd1, char *file1)
{
	int	infile;

	infile = open(file1, O_RDONLY);
	if (infile == -1)
	{
		perror("Error al abrir el archivo de entrada");
		exit(EXIT_FAILURE);
	}
	if (dup2(infile, 0) == -1)
	{
		perror("Error duplicating file descriptor");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[1], 1) == -1)
	{
		perror("Error duplicating file descriptor");
		exit(EXIT_FAILURE);
	}
	if (close(fd[0]) == -1 || close(infile) == -1)
	{
		perror("Error closing file descriptor");
		exit(EXIT_FAILURE);
	}
	execute_command(cmd1);
}

void	parent_process(int fd[], char **cmd2, char *file2)
{
	int	outfile;

	outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror("Error abriendo el archivo de salida");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("Error al duplicar el archivo");
		exit(EXIT_FAILURE);
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		perror("Error al duplicar el outfile");
		exit(EXIT_FAILURE);
	}
	if (close(fd[1]) == -1 || close(outfile) == -1)
	{
		perror("Error closing file descriptor");
		exit(EXIT_FAILURE);
	}
	execute_command(cmd2);
}

int	main(int ac, char **av)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		return (1);
	}
	if (pipe(fd) == -1)
	{
		perror("Error creando el pipe");
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error creando el child process");
		return (1);
	}
	if (pid == 0)
		child_process(fd, ft_split(av[2], ' '), av[1]);
	else
		parent_process(fd, ft_split(av[3], ' '), av[4]);
	return (0);
}
