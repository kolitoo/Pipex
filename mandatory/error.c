/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:17:19 by abourdon          #+#    #+#             */
/*   Updated: 2023/02/22 17:17:30 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
