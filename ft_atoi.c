/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 23:25:59 by mcarry            #+#    #+#             */
/*   Updated: 2021/01/26 06:53:55 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		dopolnitelno(int res, int sign, int k)
{
	if (k >= 19)
	{
		if (sign == -1)
			res = 0;
		else
			res = -1;
	}
	return (res);
}

int				ft_atoi(const char *str)
{
	int			rez;
	int			sign;
	int			k;
	size_t		i;

	i = 0;
	sign = 1;
	rez = 0;
	k = 1;
	while ((*(str + i) == '\t' || *(str + i) == '\n' || *(str + i) == '\v'\
			|| *(str + i) == '\f' || *(str + i) == '\r' || *(str + i) == ' '))
		i++;
	if ((*(str + i) == '-' || *(str + i) == '+') && ft_isdigit(*(str + i + 1)))
	{
		if (*(str + i) == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(*(str + i)))
	{
		rez = rez * 10 + (*(str + i++) - '0');
		k++;
	}
	return (sign * dopolnitelno(rez, sign, k));
}
