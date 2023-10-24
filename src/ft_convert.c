/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:46:40 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/21 15:18:44 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_chartostr(char c)
{
	char	*str;

	str = (char *) ft_calloc(2, sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*parse_flags(t_flags flags, va_list *args)
{
	if (flags.type == 'c')
		return (convert_c(flags, args));
	if (flags.type == 's')
		return (convert_s(flags, args));
	if (flags.type == 'p')
		return (convert_p(flags, args));
	if (flags.type == 'i' || flags.type == 'd')
		return (convert_id(flags, args));
	if (flags.type == 'u')
		return (convert_u(flags, args));
	if (flags.type == 'x')
		return (convert_x(flags, args));
	if (flags.type == 'X')
		return (convert_upx(flags, args));
	return (NULL);
}
