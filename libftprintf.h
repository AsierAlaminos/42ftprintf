/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:25:28 by aalamino          #+#    #+#             */
/*   Updated: 2023/06/05 13:30:16 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>

void	putnbrlonghex(unsigned long num);
void	putnbrhex(int num, char c);
void	putnbrulong(unsigned long num);
void	putnbr(int num);
void	ft_putchar(char	c);
void	ft_print_str(char *str);
void	ft_num_flags(char f, unsigned long num);
void	ft_int_flags(char f, int num);
void	ft_char_flags(char f, char *str);
int	ft_printf(char const *str, ...);

#endif
