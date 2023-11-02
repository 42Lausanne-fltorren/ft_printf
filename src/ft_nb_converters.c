/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_converters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:01:24 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/02 15:44:35 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write(char *str, int len, t_flags flags, int neg)
{
	ft_put_zeroes(flags.precision, len - neg);
	write(1, str + neg, len - neg);
}

static int	ft_put(char *str, int len, t_flags *flags)
{
	int	neg;

	neg = str[0] == '-';
	if (flags->dot && str[0] == '0')
		len = 0;
	write(1, "-", neg && flags->minus);
	if (flags->minus)
		ft_write(str, len, *flags, neg);
	if (!flags->zero || flags->minus)
		ft_put_width(flags->width, ft_max(len, flags->precision) + (neg && flags->dot));
	write(1, "-", neg && !flags->minus);
	if (flags->zero && !flags->minus)
		ft_put_zeroes(flags->width, ft_max(len, flags->precision) + (neg && flags->dot));
	if (!flags->minus)
		ft_write(str, len, *flags, neg);
	free(str);
	return (ft_max(flags->width, ft_max(len, flags->precision + neg)));
}

int	ft_put_int(va_list args, t_flags flags)
{
	int		n;
	int		len;
	char	*str;

	n = va_arg(args, int);
	str = ft_itoa(n);
	len = ft_strlen(str);
	return (ft_put(str, len, &flags));
}

int	ft_put_uint(va_list args, t_flags flags)
{
	unsigned int	n;
	int				len;
	char			*str;

	n = va_arg(args, unsigned int);
	str = ft_itoau(n);
	len = ft_strlen(str);
	return (ft_put(str, len, &flags));
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
	return (ft_put(str, len, &flags));
}
