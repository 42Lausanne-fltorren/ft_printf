/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:44:01 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/20 18:51:19 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	char	*out;
	char	*str;

	str = ft_strdup(format);
	va_start(args, format);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str != '%')
			{
				flags = get_flag(&str);
				out = parse_flags(flags, &args);
				ft_putstr_fd(out, 1);
				free(out);
			}
			else
				ft_putchar_fd(*(str++), 1);
		}
		else
			ft_putchar_fd(*(str++), 1);
	}
	va_end(args);
	return (0);
}

