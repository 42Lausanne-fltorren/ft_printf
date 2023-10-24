/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:44:14 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/20 19:00:20 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_digits(unsigned int n)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*convert_u(t_flags flags, va_list *args)
{
	char			*arg;
	int				i;
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	arg = ft_calloc(get_digits(n) + 1, sizeof(char));
	if (arg == NULL)
		return (NULL);
	i = get_digits(n);
	while (i > 0)
	{
		arg[--i] = n % 10 + '0';
		n /= 10;
	}
	return (arg);
}
