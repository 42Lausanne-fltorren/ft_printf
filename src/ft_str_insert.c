/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:11:31 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/19 23:18:57 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_slice(char *str, size_t start, size_t end)
{
	size_t	len;
	char	*slice;

	len = (end - start) + 1;
	if (str == NULL)
		return (NULL);
	if (len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	slice = (char *) ft_calloc(len + 1, sizeof(char));
	if (slice == NULL)
		return (NULL);
	slice = ft_strndup(str + start, len);
	return (slice);
}

char	*str_insert(char *str, char *insert, size_t pos)
{
	char	*start;
	char	*end;
	char	*new_str;

	if (str == NULL || insert == NULL)
		return (NULL);
	if (pos > ft_strlen(str))
		return (ft_strjoin(str, insert));
	start = str_slice(str, 0, pos - 1);
	end = str_slice(str, pos, ft_strlen(str));
	new_str = ft_strjoin(start, insert);
	new_str = ft_strjoin(new_str, end);
	free(start);
	free(end);
	return (new_str);
}
