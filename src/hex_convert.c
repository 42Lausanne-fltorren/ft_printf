/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:43:26 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/21 15:36:23 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_numlen(unsigned long n, int base)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*to_hex(unsigned long n)
{
	const char	*hex = "0123456789abcdef";
	char		*str;
	size_t		len;

	len = ft_numlen(n, 16);
	str = (char *) ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (len > 0)
	{
		str[--len] = hex[n % 16];
		n /= 16;
	}
	return (str);
}

char	*to_hex_alt(unsigned long n)
{
	const char	*hex = "0123456789abcdef";
	char		*str;
	size_t		len;

	len = ft_numlen(n, 16) + 2;
	str = (char *) ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n > 0)
	{
		str[--len] = hex[n % 16];
		n /= 16;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

char	*to_hex_up(unsigned int n)
{
	char	*str;
	size_t	i;

	str = to_hex((unsigned long) n);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

char	*to_hex_up_alt(unsigned int n)
{
	char	*str;
	size_t	i;

	str = to_hex_alt((unsigned long) n);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
