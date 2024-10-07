/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 03:09:13 by ctechy            #+#    #+#             */
/*   Updated: 2022/06/02 02:01:36 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			len;
	size_t			i;
	size_t			src_len;

	len = size - 1;
	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (!src)
		return (0);
	if (!size)
		return (src_len);
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
