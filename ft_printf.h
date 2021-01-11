/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 21:36:31 by ahammad           #+#    #+#             */
/*   Updated: 2021/01/09 15:25:55 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>

typedef struct	s_options
{
	int	zero;
	int	less;
	int	width;
	int	precision;
	int	len;
}				t_options;

typedef struct	s_format
{
	char	format;
	void	(*format_func)(va_list *, t_options *);
}				t_format;

void			ft_printf_str(va_list *my_list, t_options *op);
void			ft_printf_char(va_list *my_list, t_options *op);
void			ft_printf_nbr(va_list *my_list, t_options *op);
void			ft_printf_adress(va_list *my_list, t_options *op);
void			ft_printf_unsigned(va_list *my_list, t_options *op);
void			ft_printf_signed(va_list *my_list, t_options *op);
void			ft_printf_pourcent(va_list *my_list, t_options *op);
void			ft_printf_hexa(va_list *my_list, t_options *op);
void			ft_printf_hx(va_list *my_list, t_options *op);
void			ft_putnbr_u(unsigned int n, int *len);
void			ft_putchar(char c, int *len);
void			ft_putnbr(int n, int *len);
size_t			ft_strlen(const char *s);
void			ft_putnbr_base(long unsigned int deci, char *str_base, int *l);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			ft_putnstr(char const *s, int n, int *len);
int				ft_nbrlen(int num);
int				ft_nbrlen_u(unsigned int nbr, int base);
int				ft_nbrlen_lu(long unsigned int nbr, int base);
int				ft_abs(int n);
int				ft_printf(const char *format, ...);
int				ft_check_op(va_list *ml, const char *src, int i, t_options *o);

#endif
