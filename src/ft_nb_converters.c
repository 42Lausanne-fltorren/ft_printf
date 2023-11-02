/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_converters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:01:24 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/02 11:37:09 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put(char *str, int len, t_flags *flags)
{
	int	neg;

	neg = str[0] == '-';
	if (flags->dot && neg)
		flags->precision++;
	if (flags->width == 0)
		flags->width = ft_max(len, flags->precision);
	if (flags->minus == 1)
	{
		write(1, str, len);
		ft_put_width(flags->width, len);
	}
	else if (flags->zero == 1 || flags->dot > 0)
	{
		if (neg)
			write(1, "-", 1);
		ft_put_width(flags->width, len + flags->precision);
		ft_put_zeroes(flags->width, len);
		write(1, str + neg, len - neg);
	}
	else
	{
		ft_put_width(flags->width, len);
		write(1, str, len);
	}
	free(str);
}

int	ft_put_int(va_list args, t_flags flags)
{
	int		n;
	int		len;
	char	*str;

	n = va_arg(args, int);
	str = ft_itoa(n);
	len = ft_strlen(str);
	put(str, len, &flags);
	if (len < flags.precision)
		len = flags.precision;
	return (ft_max(flags.width, len));
}

int	ft_put_uint(va_list args, t_flags flags)
{
	unsigned int	n;
	int				len;
	char			*str;

	n = va_arg(args, unsigned int);
	str = ft_itoau(n);
	len = ft_strlen(str);
	put(str, len, &flags);
	return (ft_max(flags.width, len));
}

int	ft_put_hex(va_list args, char type, t_flags flags)
{
	unsigned int	n;
	int				len;
	char			*str;

	n = va_arg(args, unsigned int);
	str = ft_itoa_base(n, "0123456789abcdef");
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (type == 'X')
		ft_strtoupper(str);
	put(str, len, &flags);
	return (ft_max(flags.width, len));
}
