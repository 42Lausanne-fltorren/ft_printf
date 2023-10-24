/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:44:14 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/21 15:44:24 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char	*convert_id(t_flags flags, va_list *args)
{
	char	*str;
	char	*arg;
	int		i;
	int		j;

	arg = ft_itoa(va_arg(*args, int));
	if (arg == NULL)
		return (NULL);
	str = (char *) ft_calloc(ft_max(ft_strlen(arg) + (flags.space || flags.plus), flags.width),
			sizeof(char));
	if (str == NULL)
	{
		free(arg);
		return (NULL);
	}
	i = 0;
	while (i < flags.width - (int) ft_strlen(arg))
		str[i++] = ' ';
	j = 0;
	if (flags.plus && arg[0] != '-')
		str[i++] = '+';
	else if (flags.space && arg[0] != '-')
		str[i++] = ' ';
	while (arg[j])
		str[i++] = arg[j++];
	free (arg);
	return (str);
}
