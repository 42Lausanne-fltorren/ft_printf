/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:22:52 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/31 21:32:04 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put(char *str, int len, t_flags flags)
{
	if (flags.minus == 1)
	{
		write(1, "0x", 2);
		write(1, str, len);
		ft_put_width(flags.width, len + 2);
	}
	else if (flags.zero == 1)
	{
		write(1, "0x", 2);
		ft_put_zeroes(flags.width, len);
		write(1, str, len);
	}
	else
	{
		ft_put_width(flags.width, len + 2);
		write(1, "0x", 2);
		write(1, str, len);
	}
	free(str);
}

int	ft_put_ptr(va_list args, t_flags flags)
{
	uintptr_t	n;
	void		*ptr;
	char		*str;
	int			len;

	ptr = va_arg(args, void *);
	n = (uintptr_t) ptr;
	str = ft_itoa_base(n, "0123456789abcdef");
	if (!str)
		return (-1);
	len = ft_strlen(str);
	put(str, len, flags);
	if (flags.zero == 1)
		return (ft_max(flags.width + 2, len + 2));
	return (ft_max(flags.width, len + 2));
}
