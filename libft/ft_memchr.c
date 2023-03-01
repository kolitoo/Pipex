/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:40:41 by abourdon          #+#    #+#             */
/*   Updated: 2022/11/21 11:21:12 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr( const void *block, int c, size_t size )
{
	char	*tab;
	size_t	i;

	tab = (char *) block;
	i = 0;
	while (size > 0)
	{
		if (tab[i] == (char) c)
		{
			return ((char *) tab + i);
		}
		size--;
		i++;
	}
	return (NULL);
}
