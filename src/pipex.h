/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:24:07 by paromero          #+#    #+#             */
/*   Updated: 2024/04/22 12:27:31 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

char	*find_command_path(char *cmd);
void	execute_command(char **cmd);
void	child_process(int fd[], char **cmd1, char *file1);
void	parent_process(int fd[], char **cmd2, char *file2);

#endif