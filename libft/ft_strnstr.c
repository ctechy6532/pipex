/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:53:15 by ctechy            #+#    #+#             */
/*   Updated: 2022/06/02 02:05:42 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	char		*ptr;

	ptr = (char *)s1;
	i = 0;
	if (s2[0] == '\0')
		return (ptr);
	while (ptr[i] && n > i)
	{
		j = 0;
		if (s2[j] == ptr[i])
		{
			while (ptr[i + j] == s2[j] && n > (i + j)
				&& s2[j])
				j++;
			if (s2[j] == '\0')
				return ((char *)&ptr[i]);
		}
		i++;
	}
	return (NULL);
}
