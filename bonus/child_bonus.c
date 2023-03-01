/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:41:45 by abourdon          #+#    #+#             */
/*   Updated: 2023/02/27 17:49:34 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	redirect(int first, int last, t_pipex pipex)
{
	if (dup2(first, 0) == -1)
		freexit(pipex);
	if (dup2(last, 1) == -1)
		freexit(pipex);
}

static void	child2(t_pipex *pipex, char **av)
{
	char	*str;
	int		i;

	i = 0;
	str = strspace_cpy(av[pipex->i + 2], i);
	if (!str)
		freexit(*pipex);
	pipex->options = ft_split(str, ' ');
	free (str);
	if (!pipex->options)
		freexit(*pipex);
	pipex->cmd = find_cmd(pipex->cmd_path, pipex->options[0]);
	if (!pipex->cmd)
	{
		freechild(pipex);
		parent_free(pipex);
		error("Command not found\n");
		exit(127);
	}
}

void	child(t_pipex pipex, char **av, char **envp, int ac)
{
	if (pipex.i == 0)
		redirect(pipex.infile, pipex.tube[1], pipex);
	else if (pipex.i == ac - 4)
		redirect(pipex.tube[2 * pipex.i - 2], pipex.outfile, pipex);
	else
		redirect(pipex.tube[2 * pipex.i - 2],
			pipex.tube[2 * pipex.i + 1], pipex);
	close_pipes(&pipex, ac);
	child2(&pipex, av);
	if (execve(pipex.cmd, pipex.options, envp) == -1)
	{
		freechild(&pipex);
		parent_free(&pipex);
		error("Command not found\n");
		exit(127);
	}
}
