/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vivod_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:56:09 by mcarry            #+#    #+#             */
/*   Updated: 2021/01/27 01:58:05 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_vivod_s_no_m(t_flags *flags, int pre, const char *tmp, int i)
{
	if (flags->minus != 1)
	{
		if (flags->width > pre)
		{
			if (flags->zero == 1)
				while (flags->width-- > pre)
					flags->line += write(1, "0", 1);
			else if (flags->zero == 0)
				while (flags->width-- > pre)
					flags->line += write(1, " ", 1);
		}
		flags->line += write(1, tmp, pre);
	}
	return (i);
}

int			ft_vivod_s(t_flags *flags, va_list ap)
{
	const char	*tmp;
	int			i;
	int			pre;

	tmp = va_arg(ap, char*);
	if (tmp == NULL)
		tmp = "(null)";
	i = ft_strlen(tmp);
	if (flags->precision >= 0 && flags->precision < i)
		pre = flags->precision;
	else
		pre = i;
	if (flags->minus == 1)
	{
		flags->line += write(1, tmp, pre);
		if (flags->width > pre)
		{
			while (flags->width-- > pre)
				flags->line += write(1, " ", 1);
		}
	}
	ft_vivod_s_no_m(flags, pre, tmp, i);
	return (i);
}
