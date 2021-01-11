/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 21:27:38 by ahammad           #+#    #+#             */
/*   Updated: 2021/01/04 01:24:14 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_options(t_options *op)
{
	op->width = -1;
	op->less = 0;
	op->precision = -1;
	op->zero = 0;
}

static void	handle_wildcard(va_list *my_list, t_options *op)
{
	op->width = va_arg(*my_list, int);
	if (op->width < 0)
	{
		op->less = 1;
		op->width = ft_abs(op->width);
	}
}

static int	handle_dot(va_list *my_list, t_options *op, const char *src)
{
	int	i;

	i = 0;
	if (src[++i] == '*' && (++i))
	{
		op->precision = va_arg(*my_list, int);
		if (op->precision < 0)
			op->precision = -1;
	}
	else
	{
		op->precision = ft_atoi(&src[i]);
		while (ft_isdigit(src[i]))
			i++;
	}
	return (i);
}

int			ft_check_op(va_list *my_list, const char *src, int i, t_options *op)
{
	ft_init_options(op);
	while (src[i] != '\0')
	{
		if (src[i] == '-' && (++i))
			op->less = 1;
		else if (src[i] == '0' && (++i))
			op->zero = 1;
		else if (ft_isdigit(src[i]))
		{
			op->width = ft_atoi(&src[i]);
			while (ft_isdigit(src[i]))
				i++;
		}
		else if (src[i] == '.')
			i += handle_dot(my_list, op, src + i);
		else if (src[i] == '*' && (++i))
			handle_wildcard(my_list, op);
		else
			break ;
	}
	return (i);
}
