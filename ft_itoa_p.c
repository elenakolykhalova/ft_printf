/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:20:41 by mcarry            #+#    #+#             */
/*   Updated: 2021/01/26 08:41:17 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		len_number(unsigned long n)
{
	unsigned int i;

	i = 0;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i + 1);
}

char			*ft_itoa_p(unsigned long n, t_flags *flags)
{
	unsigned int	len;
	unsigned long	nb;
	unsigned int	i;
	char			*arr;
	int				small_or_big;

	small_or_big = (flags->type == 'x') ? 1 : 0;
	nb = n;
	len = len_number(nb);
	if (!(arr = (char *)malloc(sizeof(char) * len + 1 + (n < 0 ? 1 : 0))))
		return (NULL);
	i = len - 1;
	while (nb >= 16)
	{
		arr[i] = nb % 16;
		arr[i] += (arr[i] > 9) ? 87 : 48;
		arr[i] += small_or_big && arr[i] > '9' ? 32 : 0;
		nb /= 16;
		i--;
	}
	arr[i] = nb % 16;
	arr[i] += arr[i] > 9 ? 87 : 48;
	arr[i] += small_or_big && arr[i] > '9' ? 32 : 0;
	arr[len] = '\0';
	return (arr);
}
