/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_converters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:34:33 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/02 10:00:11 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(va_list args, t_flags flags)
{
	char	c;

	c = va_arg(args, int);
	if (flags.minus == 1)
	{
		write(1, &c, 1);
		if (flags.dot == 0)
			ft_put_width(flags.width, 1);
	}
	else
	{
		if (flags.dot == 0)
			ft_put_width(flags.width, 1);
		write(1, &c, 1);
	}
	if (flags.dot == 0)
		return (ft_max(flags.width, 1));
	return (1);
}

int	ft_put_str(va_list args, t_flags flags)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags.dot)
		len = ft_min(len, flags.precision);
	if (flags.minus == 1)
	{
		write(1, str, len);
		if (flags.dot == 0)
			ft_put_width(flags.width, len);
	}
	else
	{
		ft_put_width(flags.width, len);
		write(1, str, len);
	}
	if (flags.dot == 0)
		return (ft_max(flags.width, len));
	return (len);
}
