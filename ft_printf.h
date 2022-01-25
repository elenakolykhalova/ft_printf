/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:40:19 by mcarry            #+#    #+#             */
/*   Updated: 2021/01/27 04:56:16 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPEC "csdiupxX%"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h> 
# include <string.h>

typedef	struct		s_flags
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	char	type;
	int		prefix;
	char	*str;
	int		line;
	int		zerolen;
	int		spacelen;
	int		len_diux;
	char	*str_diux;
	
}					t_flags;

int			ft_printf(const char *format, ...);
int			ft_vivod_c(t_flags *flags, va_list ap);
int			ft_vivod_s(t_flags *flags, va_list ap);
int			ft_parsing(char *format, t_flags *flags, va_list *ap);
int			ft_vivod_protsent(t_flags *flags);
int			ft_atoi(const char *str);
int			ft_processing(t_flags *flags, va_list *ap);
void 		ft_filling(t_flags *flags);
void		ft_filling_s(char *tmp, t_flags *flags);
void		ft_putstr_fd(char *s, int fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_vivod_protsent(t_flags *flags);
int			ft_vivod_di(t_flags *flags, va_list ap);
int			ft_vivod_u(t_flags *flags, va_list ap);
char		*ft_itoa(unsigned int n);
int			ft_vivod_x(t_flags *flags, va_list ap);
char		*ft_itoa_hex(unsigned long n, t_flags *flags);
int			ft_vivod_p(t_flags *flags, va_list ap);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa_p(unsigned long n, t_flags *flags);
int			ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *str);

char		prefix_p(char str, t_flags t_flags, char str2);
char		*ft_flags(char *format, t_flags **flags, int *i);
char		*ft_width_star(char *format, t_flags **flags, int *i, va_list *ap);
char		*ft_width_num(char *format, t_flags **flags, int *i);
char		*ft_prec_num(char *format, t_flags **flags, int *i);
char		*ft_prec(char *format, t_flags **flags, int *i, va_list *ap);
int			ft_perc_s(int i, char *format, t_flags **flags);
int			ft_type(char **format, int i, t_flags **flags);
char		*ft_strdup(const char *s1);





#endif
