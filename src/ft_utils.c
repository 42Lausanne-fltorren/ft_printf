/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:28:37 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/31 16:01:48 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_put_width(int width, int len)
{
	while (width > len)
	{
		write(1, " ", 1);
		width--;
	}
}

void	ft_put_zeroes(int width, int len)
{
	while (width > len)
	{
		write(1, "0", 1);
		width--;
	}
}
