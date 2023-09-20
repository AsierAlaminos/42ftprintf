/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:12:09 by asmus             #+#    #+#             */
/*   Updated: 2023/09/20 17:12:39 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_long_flags(char f, va_list args)
{
	int	len;

	len = 0;
	if (f == 'p')
		len += putnbrlonghex(va_arg(args, void *), "0123456789abcdef");
	else if (f == 'u')
		len += putnbrulong(va_arg(args, unsigned int));
	return (len);
}

int	ft_flags(char f, va_list args)
{
	int		len;
	char	*str;

	len = 0;
	if (f == '%')
		len += ft_putchar('%');
	else if (f == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (f == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			return (len += ft_print_str((char *) 'n'));
		len += ft_print_str(str);
	}
	else if (f == 'd')
		len += putnbr(va_arg(args, int));
	else if (f == 'x' || f == 'X')
		len += putnbrhex(va_arg(args, unsigned long long), f);
	else if (f == 'i')
		len += putnbr(va_arg(args, int));
	else if (f == 'p' || f == 'u')
		len += ft_long_flags(f, args);
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
/*
int	main(void)
{
	int len;
	int	lenf;

	len = printf("| %x |", 9223372036854775807LL);
	printf("\n");
	lenf = ft_printf("| %x |", 9223372036854775807LL);
	printf("\nprintf: %d\tft_printf: %d\n", len, lenf);
	return (0);
}*/
