/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:01:24 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/29 23:09:20 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	if (c == '\0')
		return (-1);
	write(1, &c, 1);
	return (1);
}

int	ft_put_str(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (5);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len - 1);
}

int	ft_put_int(va_list args)
{
	int		n;
	int		len;
	char	*str;

	n = va_arg(args, int);
	str = ft_itoa(n);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len - 1);
}

int	ft_put_uint(va_list args)
{
	unsigned int	n;
	int				len;
	char			*str;

	n = va_arg(args, unsigned int);
	str = ft_itoau(n);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len - 1);
}

int	ft_put_hex(va_list args, char type)
{
	unsigned long	n;
	int				len;
	char			*str;

	n = va_arg(args, unsigned long);
	str = ft_itoa_base(n, "0123456789abcdef");
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (type == 'X')
		ft_strtoupper(str);
	if (type == 'p')
	{
		write(1, "0x", 2);
		len += 2;
	}
	write(1, str, len);
	free(str);
	return (len - 1);
}
