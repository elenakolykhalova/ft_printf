/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:17:13 by mcarry            #+#    #+#             */
/*   Updated: 2021/01/26 00:14:15 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_processing(t_flags *flags, va_list *ap)
{
	int i;

	i = 0;
	if (flags->type == 's')
		ft_vivod_s(flags, *ap);
	if (flags->type == 'c')
	{
		ft_vivod_c(flags, *ap);
		if (flags->minus == 1)
			i++;
	}
	if (flags->type == '%')
		ft_vivod_protsent(flags);
	if (flags->type == 'u')
		ft_vivod_u(flags, *ap);
	if (flags->type == 'd' || flags->type == 'i')
		ft_vivod_di(flags, *ap);
	if (flags->type == 'x' || flags->type == 'X')
		ft_vivod_x(flags, *ap);
	if (flags->type == 'p')
		ft_vivod_p(flags, *ap);
	return (i);
}
