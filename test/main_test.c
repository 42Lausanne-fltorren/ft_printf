/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:48:24 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/21 15:45:50 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


// Function to test the "%c" format
void	test_c(void)
{
	printf("============== TEST_C ==============\n");
	ft_printf("ft_printf: Test %%c: %c\n", 'c');
	printf("printf: Test %%c: %c\n", 'c');
}

void	test_s(void)
{
	printf("============== TEST_S ==============\n");
	ft_printf("ft_printf: %s, %s, %s\n", "Hello World!", (char *) NULL, "");
	printf("printf: %s, %s, %s\n", "Hello World!", (char *) NULL, "");
}

void	test_p(void)
{
	void	*ptr;

	printf("============== TEST_P ==============\n");
	ft_printf("ft_printf: %p\n", ptr);
	printf("printf: %p\n", ptr);
}

void	test_d(void)
{
	printf("============== TEST_D ==============\n");
	ft_printf("ft_printf: %d, %d, %d, %d, %d\n", 42, -42, 0, 042, 0x42);
	printf("printf: %d, %d, %d, %d, %d\n", 42, -42, 0, 042, 0x42);
}

void	test_i(void)
{
	printf("============== TEST_I ==============\n");
	ft_printf("ft_printf: %i, %i, %i, %i, %i\n", 42, -42, 0, 042, 0x42);
	printf("printf: %i, %i, %i, %i, %i\n", 42, -42, 0, 042, 0x42);
}

void	test_u(void)
{
	printf("============== TEST_U ==============\n");
	ft_printf("ft_printf: %u, %u, %u, %u, %u\n", 42, -42, 0, 042, 0x42);
	printf("printf: %u, %u, %u, %u, %u\n", 42, -42, 0, 042, 0x42);
}

void	text_x(void)
{
	printf("============== TEST_X ==============\n");
	ft_printf("ft_printf: %x, %x, %x, %x, %x\n", 42, -42, 0, 042, 0x42);
	printf("printf: %x, %x, %x, %x, %x\n", 42, -42, 0, 042, 0x42);
}

void	text_X(void)
{
	printf("============== TEST_X ==============\n");
	ft_printf("ft_printf: %X, %X, %X, %X, %X\n", 42, -42, 0, 042, 0x42);
	printf("printf: %X, %X, %X, %X, %X\n", 42, -42, 0, 042, 0x42);
}

void	test_alternate(void)
{
	printf("============== TEST_ALTERNATE ==============\n");
	ft_printf("ft_printf: %#x, %#x, %#X, %#X\n", 42, 0, 42, 0);
	printf("printf: %#x, %#x, %#X, %#X\n", 42, 0, 42, 0);
}

void	test_space(void)
{
	printf("============== TEST_SPACE ==============\n");
	ft_printf("ft_printf: % d, % i, % d, % d\n", 42, -42, 0, 042);
	printf("printf: % d, % i, % d, % d\n", 42, -42, 0, 042);
}

void	test_plus(void)
{
	printf("============== TEST_PLUS ==============\n");
	ft_printf("ft_printf: %+d, %+i, %+d, %+d\n", 42, -42, 0, 042);
	printf("printf: %+d, %+i, %+d, %+d\n", 42, -42, 0, 042);
}

int	main(void)
{
	test_c();
	test_s();
	test_p();
	test_d();
	test_i();
	test_u();
	text_x();
	text_X();
	test_alternate();
	test_space();
	test_plus();
	return (0);
}
