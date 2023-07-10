/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmus <asmus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:12:09 by asmus             #+#    #+#             */
/*   Updated: 2023/07/10 15:13:55 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_flags(char f, va_list args)
{
	int	len;

	len = 0;
	if (f == '%')
		len += ft_putchar('%');
	else if (f == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (f == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (f == 'd')
		len += putnbr(va_arg(args, int));
	else if (f == 'x' || f == 'X')
		len += putnbrhex(va_arg(args, int), f);
	else if (f == 'i')
		len += putnbr(va_arg(args, int));
	else if (f == 'p')
		len += putnbrlonghex(va_arg(args, unsigned long));
	else if (f == 'u')
		len += putnbrulong(va_arg(args, unsigned long));
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += ft_flags(str[i + 1], args);
			++i;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	int len;
	//int	lenf;

	len = printf("NULL %s NULL", NULL);
	//lenf = ft_printf("NULL %s NULL", NULL);
	//printf("printf: %d\nft_printf: %d\n", len, lenf);
	return (0);
}
