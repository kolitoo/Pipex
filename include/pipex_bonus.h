/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:27:19 by abourdon          #+#    #+#             */
/*   Updated: 2023/03/01 17:30:46 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
# define ARGBONUS "Invalid nb of arguments.\nEntrez: ./pipex infile [cmd] [cmd] outfile"

typedef struct s_pipex
{
	pid_t	*pid;
	int		*tube;
	int		infile;
	int		outfile;
	int		i;
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
void	child(t_pipex pipex, char **av, char **envp, int ac);
void	init_child_process(char **envp, char **av, t_pipex *pipex);
void	close_pipes(t_pipex *pipex, int ac);
void	init_fd(t_pipex *pipex, char **av, int ac);
void	close_pipes(t_pipex *pipex, int ac);
void	msg_perror(char *str);
void	freexit(t_pipex pipex);
void	init_pid(t_pipex *pipex, int ac, char **envp);
void	make_child(t_pipex *pipex, int ac, char **av, char **envp);
void	waitt(t_pipex *pipex, int status, int ac);
int		error(char *str);

#endif