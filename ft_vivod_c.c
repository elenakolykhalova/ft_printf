/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vivod_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:56:09 by mcarry            #+#    #+#             */
/*   Updated: 2021/01/26 15:11:48 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_filling(t_flags *flags)
{
	if (flags->width > 1)
	{
		while (flags->width-- - 1)
		{
			if (flags->zero == 1 && flags->minus != 1)
				flags->line += write(1, "0", 1);
			else
				flags->line += write(1, " ", 1);
		}
	}
}

int		ft_vivod_c(t_flags *flags, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	if (flags->minus == 1)
	{
		flags->line += write(1, &c, 1);
		ft_filling(flags);
	}
	if (flags->minus != 1)
	{
		ft_filling(flags);
		flags->line += write(1, &c, 1);
	}
	return (1);
}

int		ft_vivod_protsent(t_flags *flags)
{
	if (flags->width > 0 && flags->minus != 1)
		ft_filling(flags);
	flags->line += write(1, "%", 1);
	if (flags->minus == 1)
		ft_filling(flags);
	return (0);
}
