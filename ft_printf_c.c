/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 00:23:42 by ahammad           #+#    #+#             */
/*   Updated: 2021/01/03 21:59:08 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_char(va_list *my_list, t_options *op)
{
	char	c;

	c = va_arg(*my_list, int);
	if (op->less == 1)
		ft_putchar(c, &op->len);
	while (op->width > 1)
	{
		ft_putchar(' ', &op->len);
		op->width--;
	}
	if (op->less == 0)
		ft_putchar(c, &op->len);
}
