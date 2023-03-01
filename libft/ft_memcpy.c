/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:07:35 by abourdon          #+#    #+#             */
/*   Updated: 2022/11/23 11:26:46 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tabd;
	char	*tabs;

	if (!dest && !src)
		return (NULL);
	tabd = (char *) dest;
	tabs = (char *) src;
	i = 0;
	while (i < n)
	{
		tabd[i] = tabs[i];
		i++;
	}
	return (dest);
}
