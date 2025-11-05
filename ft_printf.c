/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:32:15 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/05 13:57:44 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int nb)
{
	int	div;
	int	modulo;
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		modulo = nb % 10;
		div = nb / 10;
		count += ft_putnbr(div);
		count += ft_putchar(modulo + '0');
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}

int	conversion(char str, va_list ap)
{
	int	count;

	count = 0;
	if (str == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (str == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (str == 'x' || str == 'X')
		count += ft_put_hex(va_arg(ap, int), str);
	else if (str == 'u')
		count += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (str == 'p')
		count += ft_put_hex_ptr(va_arg(ap, void *));
	else if (str == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!str)
	{
		return (-1);
	}
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += conversion(str[i], ap);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

// #include <stdio.h>
// #include <limits.h>
// int main(void)
// {
// 	int		ret1, ret2;
// 	printf("\n=== 🔍 TEST DE BASE ===\n");
// 	ret1 = printf("printf : Salut %s!\n", "Ryan");
// 	ret2 = ft_printf("printf : Salut %s!\n", "Ryan");
// 	printf("return printf = %d | return ft_printf = %d\n\n", ret1, ret2);
// 	printf("=== 🔢 TEST D'ENTIERS ===\n");
// 	ret1 = printf("printf : %d %i %u\n", 42, -42, 4294967295U);
// 	ret2 = ft_printf("printf : %d %i %u\n", 42, -42, 4294967295U);
// 	printf("return printf = %d | return ft_printf = %d\n\n", ret1, ret2);
// 	printf("=== 🧮 TEST HEXADECIMAL ===\n");
// 	ret1 = printf("printf : %x %X\n", 255, 255);
// 	ret2 = ft_printf("printf : %x %X\n", 255, 255);
// 	printf("return printf = %d | return ft_printf = %d\n\n", ret1, ret2);
// 	printf("=== 📍 TEST DES POINTEURS ===\n");
// 	int n = 42;
// 	ret1 = printf("printf : %p\n", &n);
// 	ret2 = ft_printf("printf : %p\n", &n);
// 	printf("return printf = %d | return ft_printf = %d\n\n", ret1, ret2);
// 	printf("=== 🧠 TESTS DE CAS LIMITES ===\n");
// 	ret1 = printf("printf : %d | %d | %u | %x\n",
//  INT_MAX, INT_MIN, UINT_MAX, 0);
// 	ret2 = ft_printf("printf : %d | %d | %u | %x\n",
//  INT_MAX, INT_MIN, UINT_MAX, 0);
// 	printf("return printf = %d | return ft_printf = %d\n\n", ret1, ret2);
// 	printf("=== ⚙️ TEST AVEC %% ET CARACTÈRES ===\n");
// 	ret1 = printf("printf : %% %c %s\n", 'A', "Test");
// 	ret2 = ft_printf("printf : %% %c %s\n", 'A', "Test");
// 	printf("return printf = %d | return ft_printf = %d\n\n", ret1, ret2);
// 	printf("=== 📏 TEST CHAÎNES VIDES ET NULL ===\n");
// 	ret1 = printf("printf : %s %p\n", "", NULL);
// 	ret2 = ft_printf("printf : %s %p\n", "", NULL);
// 	printf("return printf = %d | return ft_printf = %d\n\n", ret1, ret2);
// 	printf("=== 🧩 TESTS MIXTES ===\n");
// 	ret1 = printf("printf : char=%c | str=%s | int=%d | hex=%x 
//	| ptr=%p %%\n",'Z', "42", 1337, 3735928559U, &n);
// 	ret2 = ft_printf("printf : char=%c | str=%s | int=%d | hex=%x 
//	| ptr=%p %%\n",'Z', "42", 1337, 3735928559U, &n);
// 	printf("return printf = %d | return ft_printf = %d\n\n", ret1, ret2);
// 	printf("return printf = %d | return ft_printf = %d\n\n", 
//	printf(NULL), ft_printf(NULL));
// 	printf("return printf = %d | return ft_printf = %d\n\n", printf(""), 
//  ft_printf(""));
// 	printf("return printf = %d | return ft_printf = %d\n\n", 
//	printf("%p", NULL), 
//	ft_printf("%p", NULL));
// 	return (0);
// }
