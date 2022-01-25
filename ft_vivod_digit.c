/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vivod_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:52:05 by mcarry            #+#    #+#             */
/*   Updated: 2021/01/27 04:55:48 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_minus(t_flags *flags, int spacelen)
{
	if (flags->minus != 1)
	{
		if (flags->zero == 0)
		{
			while (spacelen-- > 0)
				flags->line += write(1, " ", 1);
			if (flags->prefix == 1)
				flags->line += write(1, "-", 1);
		}
		if ((flags->zero == 1) && (flags->precision == -1))
		{
			if (flags->prefix == 1)
				flags->line += write(1, "-", 1);
			while (spacelen-- > 0)
				flags->line += write(1, "0", 1);
		}
	}
	else if (flags->prefix == 1)
		flags->line += write(1, "-", 1);
	return (spacelen);
}

static int	ft_nbr(t_flags *flags, va_list ap)
{
	int							nbr;

	nbr = va_arg(ap, int);
	if (nbr < 0)
	{
		nbr = -nbr;
		flags->prefix = 1;
	}
	return (nbr);
}

int			ft_vivod_di(t_flags *flags, va_list ap)
{
	flags->str_diux = ft_itoa(ft_nbr(flags, ap));
	if (*(flags->str_diux) == '0' && flags->precision == 0)
	{
		free(flags->str_diux);
		flags->str_diux = ft_strdup("");
	}
	flags->len_diux = ft_strlen(flags->str_diux);
	flags->zerolen = 0;
	flags->spacelen = 0;
	if (flags->precision > flags->len_diux)
		flags->zerolen = flags->precision - flags->len_diux;
	if (flags->width > flags->len_diux)
		flags->spacelen = flags->width - flags->len_diux - flags->zerolen;
	if (flags->prefix == 1 && flags->spacelen > 0)
		flags->spacelen--;
	flags->spacelen = ft_minus(flags, flags->spacelen);
	while (flags->zerolen-- > 0)
		flags->line += write(1, "0", 1);
	flags->line += write(1, flags->str_diux, flags->len_diux);
	if (flags->minus == 1)
		while (flags->spacelen-- > 0)
			flags->line += write(1, " ", 1);
	free(flags->str_diux);
	return (0);
}
