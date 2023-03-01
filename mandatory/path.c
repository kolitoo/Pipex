/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:00:57 by abourdon          #+#    #+#             */
/*   Updated: 2023/03/01 11:06:51 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	return (envp[i] + 5);
}

char	*find_cmd(char **path, char *cmd)
{
	char	*temp;
	char	*cmd_path;
	int		j;

	j = 0;
	while (path[j] != NULL)
	{
		temp = ft_strjoin(path[j], "/");
		cmd_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(cmd_path, 0) == 0)
			return (cmd_path);
		free(cmd_path);
		j++;
	}
	if (access(cmd, 0) == 0)
		return (cmd);
	return (NULL);
}

int	countlen(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ' && str[i] != '\0')
				i++;
			if (str[i] != '\0')
				count++;
		}
		if (str[i] == '\0')
			break ;
		count++;
		i++;
	}
	return (count);
}

char	*strspace_cpy(char *str, int i)
{
	int		j;
	char	*result;

	j = 0;
	result = malloc(sizeof(char *) * (countlen(str) + 1));
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			while ((str[i] == ' ') && str[i] != '\0')
				i++;
			if (str[i] > 32)
				result[j++] = ' ';
		}
		if (str[i] == '\0')
			break ;
		if (str[i] != '\0')
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}
