/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:50:25 by abourdon          #+#    #+#             */
/*   Updated: 2022/11/21 11:21:15 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	size_t			i;
	unsigned char	*tab1;
	unsigned char	*tab2;

	tab1 = (unsigned char *) s1;
	tab2 = (unsigned char *) s2;
	i = 0;
	while (size != 0)
	{
		if (tab1[i] != tab2[i])
		{
			return (tab1[i] - tab2[i]);
		}
		i++;
		size--;
	}
	return (0);
}
