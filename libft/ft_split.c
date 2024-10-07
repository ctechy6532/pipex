/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 07:09:52 by ctechy            #+#    #+#             */
/*   Updated: 2022/06/02 11:10:04 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_nbr_words(char const *s, char c)
{
	int	i;
	int	j;
	int	bool;

	i = 0;
	j = 0;
	bool = 0;
	while (s[j])
	{
		if (s[j] != c && bool == 0)
		{
			bool = 1;
			i++;
		}
		else if (s[j] == c)
			bool = 0;
		j++;
	}
	return (i);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ft_free(char **dest, int j)
{
	while (j > 0)
	{
		free(dest[j]);
		j--;
	}
	free(dest);
	return (NULL);
}

static char	**ft_make(const char *s, char **dest, char c, int words)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] && j < words)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dest[j] = malloc(sizeof(char) * ft_size_word(s, c, i) + 1);
		if (!dest[j])
			return (ft_free(dest, j));
		while (s[i] && s[i] != c)
		{
			dest[j][k] = s[i];
			k++;
			i++;
		}
		dest[j][k] = '\0';
		j++;
	}
	dest[j] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		words;

	if (!s)
		return (NULL);
	words = ft_nbr_words(s, c);
	dest = malloc(sizeof(char *) * (words + 1));
	if (!dest)
		return (NULL);
	return (ft_make(s, dest, c, words));
}
