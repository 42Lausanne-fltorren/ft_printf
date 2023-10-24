/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:44:53 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/24 12:09:59 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "libft.h"

typedef struct s_flags
{
	int			minus;
	int			zero;
	int			width;
	int			precision;
	int			alternate;
	int			space;
	int			plus;
	char		type;
}				t_flags;

int		ft_printf(const char *format, ...);

size_t	count_args(const char *format);
t_flags	*get_flags(const char *format);
t_flags	get_flag(char *format, int *i);

char	*str_slice(char *str, size_t start, size_t end);
char	*str_insert(char *str, char *insert, size_t pos);

char	*parse_flags(t_flags flag, va_list *args);

char	*convert_c(t_flags flags, va_list *args);
char	*convert_s(t_flags flags, va_list *args);
char	*convert_p(t_flags flags, va_list *args);
char	*convert_id(t_flags flags, va_list *args);
char	*convert_u(t_flags flags, va_list *args);
char	*convert_x(t_flags flags, va_list *args);
char	*convert_upx(t_flags flags, va_list *args);

char	*to_hex(unsigned long n);
char	*to_hex_up(unsigned int n);
char	*to_hex_up_alt(unsigned int n);
char	*to_hex_alt(unsigned long n);

#endif
