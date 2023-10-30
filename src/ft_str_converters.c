/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_converters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:34:33 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/30 14:34:39 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (0);
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
