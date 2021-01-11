/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 00:46:01 by ahammad           #+#    #+#             */
/*   Updated: 2021/01/03 21:59:08 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long unsigned int decimal, char *str_base, int *len)
{
	int type_base;

	type_base = ft_strlen(str_base);
	if (decimal >= 16)
	{
		ft_putnbr_base(decimal / type_base, str_base, len);
		ft_putchar(str_base[decimal % type_base], len);
	}
	if (decimal < 16)
	{
		ft_putchar(str_base[decimal], len);
	}
}
