/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:02:40 by itulgar           #+#    #+#             */
/*   Updated: 2023/12/28 17:53:01 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char type)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, type);
	if (n % 16 < 10)
		len += ft_putchar((n % 16) + '0');
	else
	{
		if (type == 'x')
			len += ft_putchar((n % 16) - 10 + 'a');
		else
			len += ft_putchar((n % 16) - 10 + 'A');
	}
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putchar(n % 10 + '0');
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}
