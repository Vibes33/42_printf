/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:32:15 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/01 10:52:38 by rydelepi         ###   ########.fr       */
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
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
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
	return (count);
}

// int main (void)
// {
// 	int i;
// 	int j;
// 	unsigned int k;
// 	unsigned int l;
// 	char b[] = "gggggggggg";
// 	char c[] = "gggjjhhhhhhh";
// 	i = 190;
// 	j = 130;
// 	k = 12220;
// 	l = 33746;
// 	int var = ft_printf("test d'adresse de ptr : %p et %p ...\n",b, c);
// 	int var2 = printf("test d'adresse de ptr : %p et %p ...\n",b, c);
// 	ft_printf("test de caractere : %c et %c ...\n",'H','B');
// 	printf("resultat de print f : %c et %c ...\n",'H','B');
// 	ft_printf("test de chiffres : %d et %d ...\n",i,j);
// 	printf("resultat de print f : %d et %d ...\n",i,j);
// 	ft_printf("test d'adresse de ptr : %p et %p ...\n",b, c);
// 	printf("resultat de print f : %p et %p ...\n",b, c);
// 	ft_printf("test d'adresse de ptr : %x et %X ...\n",j, i);
// 	printf("resultat de print f : %x et %X ...\n",j, i);
// 	ft_printf("test de unsigned : %u et %u ...\n",k,l);
// 	printf("resultat de print f : %u et %u ...\n",k,l);
// 	ft_printf("return : %d \n",var);
// 	printf("return : %d", var2);
// }
