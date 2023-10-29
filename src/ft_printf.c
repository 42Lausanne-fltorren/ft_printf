/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:44:01 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/29 23:12:00 by fltorren         ###   ########.fr       */
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

#include <stdio.h>
int	main(void)
{
	int len = ft_printf("Hello, %s!\n", "world");
	int rlen = printf("Hello, %s!\n", "world");
	printf("len = %d, rlen = %d\n", len, rlen);

	len = ft_printf("Hello, %c%c%%!\n", 'w', '\0');
	rlen = printf("Hello, %c%c%%!\n", 'w', '\0');
	printf("len = %d, rlen = %d\n", len, rlen);

	len = ft_printf("Hello, %d, %d, %d, %d, %d!\n", 42, 0, 0, INT32_MAX, INT32_MIN);
	rlen = printf("Hello, %d, %d, %d, %d, %d!\n", 42, 0, 0, INT32_MAX, INT32_MIN);
	printf("len = %d, rlen = %d\n", len, rlen);

	len = ft_printf("Hello, %u, %u, %u, %u, %u!\n", 42, 0, 0, UINT32_MAX, UINT32_MAX + 1);
	rlen = printf("Hello, %u, %u, %u, %u, %u!\n", 42, 0, 0, UINT32_MAX, UINT32_MAX + 1);
	printf("len = %d, rlen = %d\n", len, rlen);

	len = ft_printf("Hello, %x, %x, %x, %x, %x!\n", 42, 0, 0, UINT32_MAX, UINT32_MAX + 1);
	rlen = printf("Hello, %x, %x, %x, %x, %x!\n", 42, 0, 0, UINT32_MAX, UINT32_MAX + 1);
	printf("len = %d, rlen = %d\n", len, rlen);

	len = ft_printf("Hello, %X, %X, %X, %X, %X!\n", 42, 0, 0, UINT32_MAX, UINT32_MAX + 1);
	rlen = printf("Hello, %X, %X, %X, %X, %X!\n", 42, 0, 0, UINT32_MAX, UINT32_MAX + 1);
	printf("len = %d, rlen = %d\n", len, rlen);

	len = ft_printf("Hello, %p, %p, %p!\n", &len, &rlen, NULL);
	rlen = printf("Hello, %p, %p, %p!\n", &len, &rlen, NULL);
	printf("len = %d, rlen = %d\n", len, rlen);
	return (0);
}
