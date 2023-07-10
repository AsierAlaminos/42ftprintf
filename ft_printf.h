/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmus <asmus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:12:21 by asmus             #+#    #+#             */
/*   Updated: 2023/07/10 14:42:45 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>

int	putnbrlonghex(unsigned long num);
int	putnbrhex(int num, char c);
int	putnbrulong(unsigned long num);
int	putnbr(int num);
int	ft_putchar(int c);
int	ft_print_str(char *str);
int	ft_num_flags(char f, unsigned long num);
int	ft_int_flags(char f, int num);
int	ft_char_flags(char f, char *str);
int	ft_printf(char const *str, ...);
int	nhexlen(int num);

#endif
