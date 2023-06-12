/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmus <asmus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:12:09 by asmus             #+#    #+#             */
/*   Updated: 2023/06/12 11:12:10 by asmus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_num_flags(char f, unsigned long num)
{
	if (f == 'p')
	{
		putnbrlonghex(num);
		return (12);
	}
	else if (f == 'u')
	{
		putnbrulong(num);
		return (1);
	}
	return (0);
}

int	ft_int_flags(char f, int num)
{
	if (f == 'd' || f == 'i')
	{
		putnbr(num);
		return (1);
	}
	else if (f == 'x' || f == 'X')
	{
		putnbrhex(num, f);
		return (1);
	}
	return (0);
}

int	ft_char_flags(char f, char *str)
{
	if (f == 'c')
	{
		ft_putchar(*str);
		return (1);
	}
	else if (f == 's')
	{
		ft_print_str(str);
		return (1);
	}
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				i += ft_putchar('%');
			else if (str[i + 1] == 'c' || str[i + 1] == 's')
				i += ft_char_flags(str[i + 1], va_arg(args, char *));
			else if (str[i + 1] == 'd' || str[i + 1] == 'x'
				|| str[i + 1] == 'X' || str[i + 1] == 'i')
				i += ft_int_flags(str[i + 1], va_arg(args, int));
			else
				i += ft_num_flags(str[i + 1], va_arg(args, unsigned long));
			i++;
		}
		else
			write(1, &str[i++], 1);
	}
	va_end(args);
	return (i);
}
/*
int	main(void)
{
	int len;
	int	lenf;

	len = printf("%s: %d / %x\n", "8x8", 8*8, 8*8);
	lenf = ft_printf("%s: %d / %x\n", "8x8", 8*8, 8*8);
	printf("printf: %d\nft_printf: %d\n", len, lenf);
	return (0);
}*/
