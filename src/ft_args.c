/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:17:34 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/24 12:10:34 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_args(const char *format)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
			count++;
		i++;
	}
	return (count);
}

int	isflag(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

t_flags	get_flag(char *format, int *i)
{
	t_flags	flag;

	flag = (t_flags){0, 0, 0, 0, 0, 0, 0, '\0'};
	while (isflag(format[*i]))
	{
		if (format[*i] == '-')
			flag.minus = 1;
		else if (format[*i] == '0')
			flag.zero = 1;
		else if (format[*i] == '.')
			flag.precision = 1;
		else if (format[*i] == '#')
			flag.alternate = 1;
		else if (format[*i] == ' ')
			flag.space = 1;
		else if (format[*i] == '+')
			flag.plus = 1;
		(*i)++;
	}
	// flag.width = ft_atoi(format);
	flag.type = format[*i];
	(*i)++;

	return (flag);
}
