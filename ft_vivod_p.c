/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vivod_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:14:03 by mcarry            #+#    #+#             */
/*   Updated: 2021/01/27 04:51:54 by mcarry           ###   ########.fr       */
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

static char	*ft_get_string(t_flags *flags, va_list ap)
{
	char				*str2;
	char				*str;

	str2 = ft_itoa_p(va_arg(ap, unsigned long), flags);
	if (*str2 == '0' && flags->precision == 0)
		str = ft_strdup("0x");
	else
		str = ft_strjoin("0x", str2);
	if (str2 == (void*)0 && flags->precision == 0)
	{
		if (str)
			free(str);
		str = ft_strdup("0x");
	}
	free(str2);
	return (str);
}

int			ft_vivod_p(t_flags *flags, va_list ap)
{
	flags->str_diux = ft_get_string(flags, ap);
	flags->zerolen = 0;
	flags->spacelen = 0;
	if (flags->precision > (flags->len_diux = ft_strlen(flags->str_diux)))
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
