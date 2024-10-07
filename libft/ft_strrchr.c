/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:17:25 by ctechy            #+#    #+#             */
/*   Updated: 2022/06/02 02:07:05 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	int		len;

	len = -1;
	count = 0;
	while (s[count])
	{
		if (s[count] == (char) c)
			len = count;
		count++;
	}
	if ((char) c == '\0')
		len = count;
	if (len == -1)
		return (NULL);
	else
		return ((char *)&s[len]);
}
