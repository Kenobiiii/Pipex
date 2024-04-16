/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:23:40 by paromero          #+#    #+#             */
/*   Updated: 2024/04/16 09:46:59 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Definiciones de las funciones principales
char	*find_binary(char *command);
char	**build_arguments(char *command, char **argv);
void	execute_command(char *binary_path, char **arguments);
void	check_files_existence(char *infile, char *outfile);
int		create_pipe(int pipefd[2]);
void	wait_for_children(int num_children);

// Función principal pipex
// void	pipex(char *infile, char *outfile, char *command1, char *command2)
// {
// 	int		pipefd[2];
// 	pid_t	pid1;
// 	pid_t	pid2;

// 	check_files_existence(infile, outfile);
// 	if (create_pipe(pipefd) == -1 
// 		perror("Error al crear la tubería o los procesos hijos");
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (pid1 == 0)
// 	{
// 		build_arguments(command1, NULL);
// 		execute_command(find_binary(command1), args1);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else if (pid2 == 0)
// 	{
// 		build_arguments(command2, NULL);
// 		execute_command(find_binary(command2), args2);
// 		exit(EXIT_SUCCESS);
// 	}
// 	close(pipefd[0]);
// 	close(pipefd[1]);
// 	wait_for_children(2);
// }

// int	main(int argc, char *argv[])
// {
// 	if (argc != 5)
// 	{
// 		fprintf(stderr, "Uso: %s infile outfile command1 command2\n", argv[0]);
// 		return (EXIT_FAILURE);
// 	}
// 	pipex(argv[1], argv[2], argv[3], argv[4]);
// 	return (EXIT_SUCCESS);
// }

int	main()
{
	write(1, "1", 1);
}
