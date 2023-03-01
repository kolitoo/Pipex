/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:20:09 by abourdon          #+#    #+#             */
/*   Updated: 2022/11/23 11:39:15 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tabd;
	char	*tabs;

	tabd = (char *) dest;
	tabs = (char *) src;
	i = -1;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n != 0)
		{
			tabd[n - 1] = tabs[n - 1];
			n--;
		}
	}
	else
	{
		while (++i < n)
			tabd[i] = tabs[i];
	}
	return (dest);
}
