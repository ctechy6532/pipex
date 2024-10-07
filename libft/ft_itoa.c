/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:57:57 by ctechy            #+#    #+#             */
/*   Updated: 2022/06/02 06:08:24 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_len(int n)
{
	int				len;
	unsigned int	nb;

	len = 0;
	nb = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		nb = n * -1;
	}
	else
		nb = n;
	while (nb > 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

static void	ft_swap_to_char(char *str, unsigned int nb, int i)
{
	if (nb == 0)
	{
		str[0] = 48;
	}
	while (nb > 0)
	{
		str[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	int				i;

	nb = n;
	i = ft_len(nb);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n < 0)
	{
		str[0] = '-';
		nb = n * -1;
	}
	ft_swap_to_char(str, nb, i);
	return (str);
}
