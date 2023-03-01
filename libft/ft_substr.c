/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:45:24 by abourdon          #+#    #+#             */
/*   Updated: 2022/11/23 12:37:26 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(size_t len, unsigned int start, int size_str)
{
	if (len > (size_t)size_str && start > (size_t)size_str)
		return (1);
	else if (len >= (size_t)size_str)
		return (((size_t)size_str - start) + 1);
	else if (start > len)
		return (1);
	else
		return (len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	e;
	char	*str;

	if (!s)
		return (NULL);
	e = ft_size(len, start, ft_strlen(s));
	str = malloc(sizeof(char) * e);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
