/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:59:07 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/20 18:50:42 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_s(t_flags flags, va_list *args)
{
	char	*str;
	char	*arg;
	int		i;

	arg = va_arg(*args, char *);
	if (arg == NULL)
		arg = "(null)";
	str = (char *) ft_calloc(ft_strlen(arg) + flags.width, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < flags.width - (int) ft_strlen(arg))
		str[i++] = ' ';
	while (*arg)
		str[i++] = *arg++;
	return (str);
}
