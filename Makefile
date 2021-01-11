# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/12 16:49:26 by ahammad           #+#    #+#              #
#    Updated: 2021/01/09 11:32:10 by ahammad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf

FLAGS = -Wall -Wextra -Werror

CC = gcc

HEADER = ft_printf.h

SRCS =  ft_abs.c\
		ft_atoi.c\
		ft_isdigit.c\
		ft_nbrlen_u.c\
		ft_nbrlen.c\
		ft_printf_adress.c\
		ft_printf_c.c\
		ft_printf_hexa.c\
		ft_printf_hx.c\
		ft_printf_pourcent.c\
		ft_printf_signed.c\
		ft_printf_str.c\
		ft_printf_unsigned.c\
		ft_printf_nbr.c\
		ft_printf.c\
		ft_putchar.c\
		ft_putnbr_base.c\
		ft_putnbr_u.c\
		ft_putnbr.c\
		ft_putnstr.c\
		ft_strlen.c\
		ft_nbrlen_lu.c\
		ft_check_op.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $< $(FLAGS)

$(NAME): $(OBJS)
	ar rc $(NAME).a $(OBJS)
	ranlib $(NAME).a

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME).a

re: fclean all

norme:
	~/.norminette/norminette.rb $(SRCS) $(HEADER)

.PHONY : all bonus clean fclean norme re
