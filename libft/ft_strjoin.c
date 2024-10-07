/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 03:34:04 by ctechy            #+#    #+#             */
/*   Updated: 2022/06/02 11:15:48 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_add_to(char const *s1, char const *s2, char *str)
{
	unsigned int	count;
	unsigned int	i;

	i = 0;
	count = 0;
	while (s1[count])
	{
		str[i] = s1[count];
		count++;
		i++;
	}
	count = 0;
	while (s2[count])
	{
		str[i] = s2[count];
		count++;
		i++;
	}
	str[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_add_to(s1, s2, str);
	return (str);
}
