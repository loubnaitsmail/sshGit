/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:13:04 by ahammad           #+#    #+#             */
/*   Updated: 2021/01/09 15:27:56 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_format g_tab_function[] = {
	{'s', ft_printf_str},
	{'c', ft_printf_char},
	{'d', ft_printf_nbr},
	{'x', ft_printf_hexa},
	{'X', ft_printf_hx},
	{'p', ft_printf_adress},
	{'u', ft_printf_unsigned},
	{'i', ft_printf_signed},
	{'%', ft_printf_pourcent},
};
static size_t g_tab_function_len = sizeof(g_tab_function) / sizeof(t_format);

int			find_index(char element)
{
	size_t	index;

	index = 0;
	while (index < g_tab_function_len)
	{
		if (g_tab_function[index].format == element)
			return (int)(index);
		index++;
	}
	return (-1);
}

int			ft_printf(const char *src, ...)
{
	va_list		my_list;
	int			i;
	int			tmp_index;
	t_options	op;

	i = -1;
	tmp_index = 0;
	va_start(my_list, src);
	op.len = 0;
	while (src[++i] != 0)
	{
		if (src[i] == '%')
		{
			i = ft_check_op(&my_list, src, ++i, &op);
			tmp_index = find_index(src[i]);
			if (tmp_index != -1)
				g_tab_function[tmp_index].format_func(&my_list, &op);
			else
				ft_putchar(src[i], &op.len);
		}
		else if (src[i] != '%')
			ft_putchar(src[i], &op.len);
	}
	return (op.len);
}
