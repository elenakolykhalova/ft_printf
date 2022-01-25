/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:56:51 by mcarry            #+#    #+#             */
/*   Updated: 2021/01/27 04:22:20 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			init_flags(t_flags *flags)
{
	flags->prefix = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->type = '0';
}

static char			*ft_other(char *format, t_flags *flags)
{
	flags->line += write(1, format, 1);
	format++;
	return (format);
}

static int			ft_while(char *format, t_flags *flags, va_list *ap)
{
	char		*temp;

	while (*format)
	{
		if (*format == '%')
		{
			temp = (char*)format;
			while (*temp++)
			{
				if (*temp == '\0')
					return (0);
				else if (ft_strchr(SPEC, *temp))
					break ;
			}
			init_flags(flags);
			format++;
			format += ft_parsing(format, flags, ap);
			ft_processing(flags, ap);
		}
		else
			format = ft_other(format, flags);
	}
	return (1);
}

int					ft_printf(const char *format, ...)
{
	t_flags		flags;
	va_list		ap;
	char		*itr;

	itr = (char *)format;
	flags.line = 0;
	va_start(ap, format);
	if (ft_while(itr, &flags, &ap) == 0)
		return (0);
	va_end(ap);
	return (flags.line);
}
