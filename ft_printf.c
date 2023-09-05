/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmus <asmus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:12:09 by asmus             #+#    #+#             */
/*   Updated: 2023/09/05 13:13:59 by aalamino         ###   ########.fr       */
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
		len += putnbrlonghex(va_arg(args, unsigned long));
	else if (f == 'u')
		len += putnbrulong(va_arg(args, unsigned long));
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
		len += putnbrhex(va_arg(args, int), f);
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

int	main(void)
{
	int len;
	int	lenf;

	len = printf(" %p ", 17);
	lenf = ft_printf(" %p ", 17);
	printf("printf: %d\nft_printf: %d\n", len, lenf);
	return (0);
}
