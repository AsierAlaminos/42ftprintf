/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:22:00 by aalamino          #+#    #+#             */
/*   Updated: 2023/09/09 15:06:34 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str == (char *) 'n')
		str = "(null)";
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		++i;
	}
	return (i);
}

int	nhexlen(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 16;
		++len;
	}
	return (len);
}
