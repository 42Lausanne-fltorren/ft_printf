/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:44:53 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/04 16:43:06 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	int		plus;
	int		space;
	int		alt;
}				t_flags;

int		ft_printf(const char *format, ...);
int		ft_put_type(va_list args, const char *format, int i, t_flags flags);
int		ft_get_flags(va_list args, const char *format, int i, t_flags *flags);

int		ft_put_char(va_list args, t_flags flags);
int		ft_put_str(va_list args, t_flags flags);
int		ft_put_int(va_list args, t_flags flags);
int		ft_put_uint(va_list args, t_flags flags);
int		ft_put_hex(va_list args, char type, t_flags flags);
int		ft_put_ptr(va_list args, t_flags flags);
int		ft_put_perc(t_flags flags);

size_t	ft_get_digits(unsigned long n, int base);
char	*ft_itoau(unsigned int n);
char	*ft_itoa_base(unsigned long n, char *base);
char	*ft_strtoupper(char *str);
void	ft_put_width(int width, int len);
void	ft_put_zeroes(int width, int len);

void	ft_reassign(char **str, char *new);
char	*ft_join_spaces(char *str, int n);
char	*ft_join_zeroes(char *str, int n);

int		ft_max(int a, int b);
int		ft_min(int a, int b);
#endif
