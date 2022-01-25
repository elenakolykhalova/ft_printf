# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 12:13:42 by mcarry            #+#    #+#              #
#    Updated: 2021/01/27 05:19:30 by mcarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_processing.c ft_atoi.c ft_isdigit.c ft_parsing.c\
ft_printf.c ft_strchr.c ft_strdup.c ft_strlen.c ft_strdup.c\
ft_strrchr.c ft_vivod_c.c ft_vivod_s.c ft_strjoin.c ft_itoa_p.c\
ft_putstr_fd.c ft_substr.c ft_vivod_digit.c ft_itoa.c ft_itoa_hex.c\
ft_vivod_p.c ft_vivod_u.c ft_vivod_x.c ft_parsing_utils.c\

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
