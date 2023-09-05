/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:22:00 by aalamino          #+#    #+#             */
/*   Updated: 2023/09/05 12:43:51 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(int c)
{
	char	num;

	num = c + '0';
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
