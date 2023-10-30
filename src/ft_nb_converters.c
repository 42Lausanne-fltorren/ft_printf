/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_converters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:01:24 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/30 14:40:39 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	write(1, str, len);
	free(str);
	return (len - 1);
}

int	ft_put_ptr(va_list args)
{
	uintptr_t	n;
	void		*ptr;
	char		*str;
	int			len;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (4);
	}
	n = (uintptr_t) ptr;
	str = ft_itoa_base(n, "0123456789abcdef");
	if (!str)
		return (-1);
	len = ft_strlen(str);
	write(1, "0x", 2);
	write(1, str, len);
	free(str);
	return (len + 1);
}
