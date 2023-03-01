/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:29:23 by abourdon          #+#    #+#             */
/*   Updated: 2023/03/01 17:30:35 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	init_fd(t_pipex *pipex, char **av, int ac)
{
	pipex->path = NULL;
	pipex->cmd_path = NULL;
	pipex->options = NULL;
	pipex->cmd = NULL;
	pipex->pid = NULL;
	pipex->tube = NULL;
	pipex->infile = open(av[1], O_RDONLY);
	pipex->outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (pipex->infile < 0)
		perror("zsh");
	if (pipex->outfile < 0)
		perror("zsh");
}

void	init_pipes(t_pipex *pipex, int ac)
{
	int	i;

	i = 0;
	pipex->tube = malloc(sizeof(int) * ((ac - 3) * 2));
	if (!pipex->tube)
		exit(EXIT_FAILURE);
	while (i < ac - 3)
	{
		if (pipe(pipex->tube + 2 * i) == -1)
			parent_free(pipex);
		i++;
	}
}

void	make_child(t_pipex *pipex, int ac, char **av, char **envp)
{
	while (pipex->i < ac - 3)
	{
		pipex->pid[pipex->i] = fork();
		if (pipex->pid[pipex->i] == -1)
		{
			close_pipes(pipex, ac);
			parent_free(pipex);
			msg_perror("fork error\n");
		}
		if (pipex->pid[pipex->i] == 0)
			child(*pipex, av, envp, ac);
		pipex->i++;
	}
	pipex->i--;
}

void	waitt(t_pipex *pipex, int status, int ac)
{
	int	exitstatus;

	exitstatus = 0;
	while (pipex->i >= 0)
	{
		if (waitpid(pipex->pid[pipex->i], &status, 0) == -1)
		{
			close_pipes(pipex, ac);
			parent_free(pipex);
			msg_perror("waitpid error\n");
		}
		if (pipex->i == (ac - 4) && WIFEXITED(status) != 0)
			exitstatus = WEXITSTATUS(status);
		pipex->i--;
	}
	parent_free(pipex);
	exit(exitstatus);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int		status;

	pipex.i = 0;
	status = 0;
	if (envp[0] == NULL)
	{
		write(2, "envp incorrect\n", 16);
		exit(EXIT_FAILURE);
	}
	if (ac >= 5)
	{
		init_fd(&pipex, av, ac);
		init_pipes(&pipex, ac);
		init_pid(&pipex, ac, envp);
		make_child(&pipex, ac, av, envp);
		close_pipes(&pipex, ac);
		waitt(&pipex, status, ac);
	}
	else
		return (error(ARGBONUS));
}
