/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:44:14 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/24 12:12:55 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_p(t_flags flags, va_list *args)
{
	unsigned long	n;
	char			*str;

	(void) flags;
	n = va_arg(*args, unsigned long);
	str = to_hex_alt(n);
	if (str == NULL)
		return (NULL);
	return (str);
}
