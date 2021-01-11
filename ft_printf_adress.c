/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_adress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 00:53:54 by ahammad           #+#    #+#             */
/*   Updated: 2021/01/09 17:44:43 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_num(t_options *op, int flen, int num_len, unsigned long hexa)
{
	int	i;
	int plus;

	i = 0;
	if (op->precision == 0 && hexa == 0)
		plus = 1;
	else
		plus = 2;
	if ((op->width != -1) && (op->width > flen + plus && !op->less))
		while (i++ < (op->width - flen - plus))
			ft_putchar(op->zero ? '0' : ' ', &op->len);
	i = 0;
	ft_putchar('0', &op->len);
	ft_putchar('x', &op->len);
	if (flen > num_len)
		while (i++ < op->precision - num_len)
			ft_putchar('0', &op->len);
}

static void	perform_print(t_options *op, unsigned long hexa)
{
	if (op->precision != 0 || hexa != 0)
		ft_putnbr_base(hexa, "0123456789abcdef", &op->len);
}

void		ft_printf_adress(va_list *my_list, t_options *op)
{
	unsigned long	hexa;
	int				num_len;
	int				i;
	int				flen;

	hexa = (unsigned long)va_arg(*my_list, void *);
	num_len = ft_nbrlen_lu(hexa, 16);
	i = 0;
	flen = num_len;
	if (op->precision != -1)
	{
		if (op->precision > num_len)
			flen = op->precision;
		op->zero = 0;
	}
	print_num(op, flen, num_len, hexa);
	perform_print(op, hexa);
	if ((op->width != -1) && (op->width > flen + 2 && op->less))
		while (i++ < (op->width - flen - 2))
			ft_putchar(' ', &op->len);
}
