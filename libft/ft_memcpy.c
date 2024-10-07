/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:25:56 by ctechy            #+#    #+#             */
/*   Updated: 2022/06/02 06:14:50 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	if (dst == src || !n)
		return (dst);
	if (!dst && !src)
		return (NULL);
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		str1[i] = str2[i];
		i++;
	}
	return ((void *)str1);
}
