/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:16:04 by mcarry            #+#    #+#             */
/*   Updated: 2021/01/26 22:19:42 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flags(char *format, t_flags **flags, int *i)
{
	if (*format == '*' || *format == '-' || *format == '0' \
		|| ft_isdigit(*format) || *format == '.' || ft_strchr(SPEC, *format))
	{
		while (*format == '-' || *format == '0')
		{
			if (*format == '-')
			{
				(*flags)->minus = 1;
				(format)++;
				(*i)++;
			}
			if (*format == '0')
			{
				if ((*flags)->minus != 1)
					(*flags)->zero = 1;
				(format)++;
				(*i)++;
			}
		}
	}
	return (format);
}

char	*ft_width_star(char *format, t_flags **flags, int *i, va_list *ap)
{
	if (*format == '*')
	{
		(*flags)->width = va_arg(*ap, int);
		if ((*flags)->width < 0)
		{
			(*flags)->minus = 1;
			(*flags)->width = -(*flags)->width;
		}
		(*i)++;
		format++;
	}
	return (format);
}

char	*ft_width_num(char *format, t_flags **flags, int *i)
{
	int	size;

	size = 0;
	if (ft_isdigit(*format))
	{
		size = 0;
		if (*format != '0')
		{
			while (ft_isdigit(*format))
			{
				size = size * 10 + (*format - '0');
				(*i)++;
				format++;
			}
			(*flags)->width = size;
		}
	}
	return (format);
}
