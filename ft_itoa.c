/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:20:41 by mcarry            #+#    #+#             */
/*   Updated: 2021/01/26 06:57:57 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		len_number(unsigned int n)
{
	unsigned int i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char			*ft_itoa(unsigned int n)
{
	unsigned int	len;
	unsigned int	nb;
	unsigned int	i;
	char			*arr;

	nb = (n < 0 ? -n : n);
	len = len_number(nb);
	i = 0;
	if (!(arr = (char *)malloc(sizeof(char) * len + 1 + (n < 0 ? 1 : 0))))
		return (NULL);
	if (n < 0)
	{
		arr[i] = '-';
		len++;
	}
	i = len - 1;
	while (nb >= 10)
	{
		arr[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	arr[i] = nb % 10 + 48;
	arr[len] = '\0';
	return (arr);
}
