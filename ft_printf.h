/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:12:21 by asmus             #+#    #+#             */
/*   Updated: 2023/09/09 15:31:59 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>

int	putnbrlonghex(void *num, char *hex_chars);
int	putnbrhex(unsigned long long num, char c);
int	putnbrulong(unsigned int num);
int	putnbr(int num);
int	ft_putchar(int c);
int	ft_print_str(char *str);
int	ft_num_flags(char f, unsigned long num);
int	ft_int_flags(char f, int num);
int	ft_char_flags(char f, char *str);
int	ft_printf(char const *str, ...);
int	nhexlen(unsigned long long num);
int	print_hex(char *num, int size_num);

#endif
