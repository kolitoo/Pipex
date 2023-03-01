/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:30:32 by abourdon          #+#    #+#             */
/*   Updated: 2023/03/01 17:31:13 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

/*libft*/
# include "../libft/libft.h"
# define ARG "Invalid nb of arguments.\nEntrez: ./pipex infile [cmd] [cmd] outfile"

typedef struct s_pipex
{
	pid_t	pid;
	pid_t	pid1;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*path;
	char	**cmd_path;
	char	**options;
	char	*cmd;
}t_pipex;

char	*find_path(char **envp);
char	*find_cmd(char **path, char *cmd);
char	*strspace_cpy(char *str, int i);
void	freechild(t_pipex *pipex);
void	parent_free(t_pipex *pipex);
void	child(t_pipex pipex, char **av, char **envp);
void	child2(t_pipex pipex, char **av, char **envp);
void	end_pipeprocess(t_pipex *pipex);
void	init_child_process(char **envp, char **av, t_pipex *pipex);
void	msg_perror(char *err);
void	freexit(t_pipex pipex);
void	ft_wait(t_pipex pipex, int status);
void	init_fd(t_pipex *pipex, char **av, char **envp);
int		error(char *str);

#endif