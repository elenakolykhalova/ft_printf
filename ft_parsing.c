/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:52:41 by mcarry            #+#    #+#             */
/*   Updated: 2021/01/26 22:19:03 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_prec_num(char *format, t_flags **flags, int *i)
{
	int	size;

	size = 0;
	if (ft_isdigit(*format))
	{
		size = 0;
		if (*format != -1)
		{
			while (ft_isdigit(*format))
			{
				size = size * 10 + (*format - '0');
				(*i)++;
				format++;
			}
			(*flags)->precision = size;
		}
		else
		{
			(*flags)->precision = -1;
			format++;
			(*i)++;
		}
	}
	return (format);
}

char	*ft_prec(char *format, t_flags **flags, int *i, va_list *ap)
{
	if (*format == '.')
	{
		(*i)++;
		format++;
		(*flags)->precision = 0;
		if (*format == '*')
		{
			(*flags)->precision = va_arg(*ap, int);
			(*i)++;
			format++;
		}
		else
		{
			format = ft_prec_num(format, flags, i);
		}
	}
	return (format);
}

int		ft_perc_s(int i, char *format, t_flags **flags)
{
	int j;

	j = i;
	while (ft_strchr("%", *format))
	{
		j++;
		(*flags)->type = '%';
		return (j);
	}
	j = i;
	while (ft_strchr("s", *format))
	{
		j++;
		(*flags)->type = 's';
		return (j);
	}
	return (0);
}

int		ft_type(char **format, int i, t_flags **flags)
{
	if (ft_strchr("cpdiuxX", **format))
	{
		i++;
		(*flags)->type = **format;
		return (i);
	}
	if (**format == ' ')
	{
		write(1, " ", 1);
		(*format)++;
		i++;
	}
	return (i);
}

int		ft_parsing(char *format, t_flags *flags, va_list *ap)
{
	int i;

	i = 0;
	while (*format)
	{
		format = ft_flags(format, &flags, &i);
		format = ft_width_star(format, &flags, &i, ap);
		format = ft_width_num(format, &flags, &i);
		format = ft_prec(format, &flags, &i, ap);
		if (ft_strchr("%s", *format))
			return (ft_perc_s(i, format, &flags));
		if (flags->precision >= 0)
			flags->zero = 0;
		else
			flags->precision = -1;
		if (ft_strchr("cpdiuxX", *format) || *format == ' ')
			return (ft_type(&format, i, &flags));
		else
			return (0);
	}
	return (i);
}
