/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:44:01 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/02 10:42:05 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_type(va_list args, const char *format, int i, t_flags flags)
{
	if (format[i] == 'c')
		return (ft_put_char(args, flags));
	else if (format[i] == 's')
		return (ft_put_str(args, flags));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_put_int(args, flags));
	else if (format[i] == 'u')
		return (ft_put_uint(args, flags));
	else if (format[i] == 'x' || format[i] == 'X')
		return (ft_put_hex(args, format[i], flags));
	else if (format[i] == 'p')
		return (ft_put_ptr(args, flags));
	else if (format[i] == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_get_flags(va_list args, const char *format, int i, t_flags *flags)
{
	int	j;

	*flags = (t_flags){0, 0, 0, 0, 0};
	j = 0;
	while (format[i + j] == '-' || format[i + j] == '0' || format[i + j] == '.')
	{
		if (format[i + j] == '-')
			flags->minus = 1;
		else if (format[i + j] == '0')
			flags->zero = 1;
		else if (format[i + j] == '.')
			flags->dot = 1;
		j++;
	}
	if (format[i + j] == '*')
	{
		flags->width = va_arg(args, int);
		j++;
	}
	else if (format[i + j] >= '0' && format[i + j] <= '9')
	{
		if (flags->dot == 1)
		{
			flags->precision = ft_atoi(&format[i + j]);
			j += ft_get_digits(flags->precision, 10);
		}
		else
		{
			flags->width = ft_atoi(&format[i + j]);
			j += ft_get_digits(flags->width, 10);
		}
	}
	return (j);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	len;
	t_flags	flags;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			i += ft_get_flags(args, format, i, &flags);
			len += ft_put_type(args, format, i, flags);
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

#include <stdio.h>
#include <limits.h>
int	main(void)
{
	int len = ft_printf(" %.1d \n", 0);
	int rlen = printf(" %.1d \n", 0);
	printf("len = %d, rlen = %d\n", len, rlen);
	return (0);
}
