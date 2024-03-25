/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:36:23 by itulgar           #+#    #+#             */
/*   Updated: 2023/12/29 14:12:28 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list args, char c)
{
	int	total;

	total = 0;
	if (c == 'c')
		total += ft_putchar(va_arg(args, int));
	else if (c == 's')
		total += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		total += ft_putstr("0x");
		total += ft_puthex((unsigned long)va_arg(args, void *), 'x');
	}
	else if (c == 'd' || c == 'i')
		total += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		total += ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x')
		total += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'X')
		total += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		total += ft_putchar('%');
	return (total);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, s);
	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_type(args, s[i]);
		}
		else
		{
			len += ft_putchar(s[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
