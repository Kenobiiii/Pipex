/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:23:40 by paromero          #+#    #+#             */
/*   Updated: 2024/04/22 12:28:12 by paromero         ###   ########.fr       */
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
	if (!find_command_path(cmd[0]))
	{
		perror("No se ha encontrado el comando");
		exit(EXIT_FAILURE);
	}
	else
	{
		execve(find_command_path(cmd[0]), cmd, NULL);
		if (!excve)
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
	if (!infile)
	{
		perror("Error al abrir el archivo de entrada");
		exit(EXIT_FAILURE);
	}
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		perror("Error al duplicar el infile");
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	close(infile);
	execute_command(cmd1);
	perror("Error ejecutando el primer comando");
	exit(EXIT_FAILURE);
}

void	parent_process(int fd[], char **cmd2, char *file2)
{
	int	outfile;

	outfile = open(file2, O_RDONLY | O_CREAT);
	if (!outfile)
	{
		perror("Error abriendo el archivo");
		exit(EXIT_FAILURE);
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		perror("Error al duplicar el outfile");
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	close(outfile);
	execute_command(cmd2);
	perror("Error ejecutando el segundo commando");
	exit(EXIT_FAILURE);
}

int	main (int ac, char **av)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 2);
		return (1);
	}
	if (pipe(fd) == -1)
	{
		perror("Error creating pipe");
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error creating child process");
		return (1);
	}
	if (pid == 0)
		child_process(fd, ft_split(av[2], ' '), av[1]);
	else
		parent_process(fd, ft_split(av[3], ' '), av[4]);
	return (0);
}
