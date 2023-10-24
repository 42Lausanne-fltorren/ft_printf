/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:17:34 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/24 11:26:33 by fltorren         ###   ########.fr       */
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

t_flags	get_flag(char **format)
{
	t_flags	flag;
	// size_t	i;

	flag = (t_flags){0, 0, 0, 0, 0, 0, 0, '\0'};
	while (isflag(**format))
	{
		if (**format == '-')
			flag.minus = 1;
		else if (**format == '0')
			flag.zero = 1;
		else if (**format == '.')
			flag.precision = 1;
		else if (**format == '#')
			flag.alternate = 1;
		else if (**format == ' ')
			flag.space = 1;
		else if (**format == '+')
			flag.plus = 1;
		(*format)++;
	}
	// flag.width = ft_atoi(format);
	flag.type = **format;
	(*format)++;

	return (flag);
}
