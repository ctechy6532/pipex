/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 03:21:46 by ctechy            #+#    #+#             */
/*   Updated: 2022/06/02 02:10:41 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dest;
	size_t		end;
	size_t		i;

	end = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[start + end] && end < len)
		end++;
	if (start >= (unsigned int) ft_strlen(s))
		end = 0;
	dest = malloc(sizeof(char) * (end + 1));
	if (!dest)
		return (NULL);
	while (i < end)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
