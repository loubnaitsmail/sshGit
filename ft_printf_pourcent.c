/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pourcent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:53:04 by ahammad           #+#    #+#             */
/*   Updated: 2021/01/09 14:32:21 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_pourcent(va_list *my_list, t_options *op)
{
	(void)my_list;
	(void)op;
	if (op->less == 1)
	{
		ft_putchar('%', &op->len);
		while (--op->width)
		{
			ft_putchar(' ', &op->len);
		}
		return ;
	}
	while (op->width-- > 1)
	{
		if (op->zero == 1)
			ft_putchar('0', &op->len);
		else
			ft_putchar(' ', &op->len);
	}
	ft_putchar('%', &op->len);
}
