/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:58:49 by ctechy            #+#    #+#             */
/*   Updated: 2022/06/03 12:46:54 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_limit(unsigned long long nbr, int is_neg, int len)
{
	int						base;
	unsigned long long int	max;

	base = 0;
	max = LONG_MAX;
	while (max > 0)
	{
		max = max / 10;
		base++;
	}
	if (((nbr > LONG_MAX) || len > base) && is_neg > 0)
		return (-1);
	else if ((nbr > LONG_MAX || len > base) && is_neg < 0)
		return (0);
	return (nbr * is_neg);
}

static int	ft_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	nbr;
	int					is_neg;
	int					len;

	i = 0;
	is_neg = 1;
	nbr = 0;
	len = 0;
	while (ft_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_neg = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
		len++;
	}
	return (ft_limit(nbr, is_neg, len));
}
