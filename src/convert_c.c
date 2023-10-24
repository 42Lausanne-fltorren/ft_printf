/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:44:14 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/20 17:58:23 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_c(t_flags flags, va_list *args)
{
	char	*str;
	char	c;
	int		i;

	c = (char) va_arg(*args, int);
	str = (char *) ft_calloc(2 + flags.width, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < flags.width - 1)
		str[i++] = ' ';
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}
