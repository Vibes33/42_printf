/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:15:36 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/04 15:48:17 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_put_hex(unsigned int n, char str)
{
	int	count;

	count = 0;
	if (n < 16)
	{
		if (str == 'x')
			ft_putchar("0123456789abcdef"[n]);
		else
			ft_putchar("0123456789ABCDEF"[n]);
		return (1);
	}
	return (ft_put_hex(n / 16, str) + ft_put_hex(n % 16, str));
}

int	ft_put_hex_long(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_put_hex_long(n / 16);
	count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_put_hex_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_put_hex_long((unsigned long)ptr);
	return (count);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	div;
	int	modulo;
	int	count;

	count = 0;
	if (nb > 9)
	{
		modulo = nb % 10;
		div = nb / 10;
		count += ft_putnbr_unsigned(div);
		count += ft_putchar(modulo + '0');
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}
