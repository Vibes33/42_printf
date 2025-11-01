/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:57:16 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/30 11:17:32 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int			ft_printf(const char *str, ...);
/**
 * @details
 * @brief displays a character 
 * @param char.c character to display
 * @return int
 */
int			ft_putchar(char c);
/**
 * @details
 * @brief Counts the number of elements in a character string.
 * @param const.char.*str Character string.
 * @return Size of src.
 */
size_t		ft_strlen(const char *str);
/**
 * @details
 * @brief reads a character string
 * @param char.*str character string
 * @return int
 */
int			ft_putstr(char *str);
/**
 * @details
 * @brief convert a ptr adress in hexa value
 * @param void.ptr 
 * @return int
 */
int			ft_put_hex_ptr(void *ptr);
/**
 * @details
 * @brief convert in hexa value BUT only unsigned numbers
 * @param unsigned.long.n value to convert
 * @return int
 */
int			ft_put_hex_long(unsigned long n);
/**
 * @details
 * @brief convert in hexa value
 * @param unsigned.int.n 
 * @param char.str detect if its x or X 
 * @return int
 */
int			ft_put_hex(unsigned int n, char str);
/**
 * @details
 * @brief defines the first n characters of dest based on c and skips a line
 * @param unsigned int.nb character to be defined
 * @return int
 */
int			ft_putnbr_unsigned(unsigned int nb);
/**
 * @details
 * @brief defines the first n characters of dest based on c and skips a line
 * @param int.nb character to be defined
 * @return int
 */
int			ft_putnbr(int nb);

#endif