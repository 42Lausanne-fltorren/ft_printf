/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:44:53 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/30 14:09:03 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_put_type(va_list args, const char *format, int i);

int		ft_put_char(va_list args);
int		ft_put_str(va_list args);
int		ft_put_int(va_list args);
int		ft_put_uint(va_list args);
int		ft_put_hex(va_list args, char type);
int		ft_put_ptr(va_list args);

size_t	ft_get_digits(unsigned int n, int base);
char	*ft_itoau(unsigned int n);
char	*ft_itoa_base(unsigned long n, char *base);
char	*ft_strtoupper(char *str);
#endif
