/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:36:37 by abourdon          #+#    #+#             */
/*   Updated: 2023/03/01 11:52:16 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_path[i])
	{
		free(pipex->cmd_path[i]);
		i++;
	}
	free(pipex->cmd_path);
	free(pipex->tube);
	free(pipex->pid);
}

void	freechild(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->options[i] != NULL)
	{
		free(pipex->options[i]);
		i++;
	}
	free(pipex->options);
	free(pipex->cmd);
}

void	close_pipes(t_pipex *pipex, int ac)
{
	int	i;

	i = 0;
	while (i < ((ac - 4) * 2))
	{
		if (close(pipex->tube[i]) == -1)
			msg_perror("close Error\n");
		i++;
	}
}

void	freexit(t_pipex pipex)
{
	parent_free(&pipex);
	exit(EXIT_FAILURE);
}
