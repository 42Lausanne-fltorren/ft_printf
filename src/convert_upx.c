/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:44:14 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/21 15:18:24 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_upx(t_flags flags, va_list *args)
{
	if (flags.alternate)
		return (to_hex_up_alt(va_arg(*args, unsigned int)));
	return (to_hex_up(va_arg(*args, unsigned int)));
}
