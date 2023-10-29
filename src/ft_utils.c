/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:28:37 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/29 23:11:13 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_get_digits(unsigned int n, int base)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		i++;
		n /= base;
	}
	return (i);
}

char	*ft_itoau(unsigned int n)
{
	char	*str;
	size_t	i;

	str = (char *) ft_calloc(ft_get_digits(n, 10) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = ft_get_digits(n, 10);
	while (i > 0)
	{
		str[--i] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa_base(unsigned long n, char *base)
{
	char	*str;
	size_t	i;
	size_t	base_len;

	base_len = ft_strlen(base);
	str = (char *) ft_calloc(ft_get_digits(n, base_len) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = ft_get_digits(n, base_len);
	while (i > 0)
	{
		str[--i] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

char	*ft_strtoupper(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
