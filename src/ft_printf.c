/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:44:01 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/29 23:28:52 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_type(va_list args, const char *format, int i)
{
	if (format[i] == 'c')
		return (ft_put_char(args));
	else if (format[i] == 's')
		return (ft_put_str(args));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_put_int(args));
	else if (format[i] == 'u')
		return (ft_put_uint(args));
	else if (format[i] == 'x' || format[i] == 'X')
		return (ft_put_hex(args, format[i]));
	else if (format[i] == '%')
	{
		write(1, "%", 1);
		return (0);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_put_type(args, format, i) - 1;
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len + i);
}

/*#include <stdio.h>
int	main(void)
{
	int len = ft_printf(" %c %c %c ", '0', 0, '0');
	int rlen = printf(" %c %c %c ", '0', 0, '0');
	printf("len = %d, rlen = %d\n", len, rlen);
	return (0);
}*/
