/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmus37 <asmus37@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:39:25 by asmus37           #+#    #+#             */
/*   Updated: 2023/06/05 13:52:08 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	putnbrlonghex(unsigned long num);

int	putnbrhex(int num, char c);

int	putnbrulong(unsigned long num, int len);

int	putnbr(int num, int len);

int	ft_putchar(char	c);

int	ft_print_str(char *str);

int	ft_num_flags(char f, unsigned long num)
{
	if (f == 'p')
		return (putnbrlonghex(num));
	if (f == 'u')
		return (putnbrulong(num, 0));
	return (0);
}

int	ft_int_flags(char f, int num)
{
	if (f == 'd' || f == 'i')
		return (putnbr(num, 0));
	if (f == 'x' || f == 'X')
		return (putnbrhex(num, f));
	return (0);
}

int	ft_char_flags(char f, char *str)
{
	if (f == 'c')
		return (ft_putchar(*str));
	if (f == 's')
		return (ft_print_str(str));
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
			else if (str[i + 1] == 'd' || str[i + 1] == 'x' || 
					str[i + 1] == 'X' || str[i + 1] == 'i')
				i += ft_int_flags(str[i + 1], va_arg(args, int));
			else
				i += ft_num_flags(str[i + 1], va_arg(args, unsigned long));
			i += 2;
		}
		write(1, &str[i], 1);
		++i;
	}
	printf("%d\n", i);
	va_end(args);
	return (1);
}

int	main(void)
{
	int num;

	num = printf("%s\n", "esto");
	printf("%d\n", num);
	ft_printf("Esto %X = %p es un %% %s", 79, 79, "test");
	return (0);
}
