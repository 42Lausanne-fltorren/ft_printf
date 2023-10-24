/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:44:01 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/24 12:09:53 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	char	*out;
	char	*str;
	int		i;

	str = ft_strdup(format);
	va_start(args, format);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i] != '%')
			{
				flags = get_flag(str, &i);
				out = parse_flags(flags, &args);
				ft_putstr_fd(out, 1);
				free(out);
			}
			else
				ft_putchar_fd(str[i++], 1);
		}
		else
			ft_putchar_fd(str[i++], 1);
	}
	va_end(args);
	free(str);
	return (0);
}

