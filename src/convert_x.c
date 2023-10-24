/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:44:14 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/21 15:17:20 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_x(t_flags flags, va_list *args)
{
	if (flags.alternate)
		return (to_hex_alt(va_arg(*args, unsigned int)));
	return (to_hex(va_arg(*args, unsigned int)));
}
