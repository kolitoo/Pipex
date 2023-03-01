/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:02:09 by abourdon          #+#    #+#             */
/*   Updated: 2023/02/27 11:21:19 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	msg_perror(char *str)
{
	perror(str);
	exit (1);
}

int	error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}
