/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguengo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:32:21 by hguengo           #+#    #+#             */
/*   Updated: 2024/10/03 12:38:56 by hguengo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putchar(char str)
{
	return (write(1, &str, 1));
}

int	ft_putstr(char *str)
{
	int	cont;

	cont = 0;
	if (!str)
	{
		cont += ft_putstr("(null)");
	}
	else
	{
		while (*str)
			cont += ft_putchar(*(str++));
	}
	return (cont);
}

int	ft_putnbr(long long int nbr)
{
	int	cont;

	cont = 0;
	if (nbr < 0)
	{
		cont += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		cont += ft_putnbr(nbr / 10);
	}
	cont += ft_putchar("0123456789"[nbr % 10]);
	return (cont);
}

int	ft_hexa(long long int nbr)
{
	int	cont;

	cont = 0;
	if (nbr >= 16)
		cont += ft_hexa(nbr / 16);
	cont += ft_putchar("0123456789abcdef"[nbr % 16]);
	return (cont);
}

int	ft_printf(const char *str, ...)
{
	va_list		lst;
	int			cont;

	va_start(lst, str);
	cont = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 's')
				cont += ft_putstr(va_arg(lst, char *));
			else if (*str == 'd')
				cont += ft_putnbr(va_arg(lst, int));
			else if (*str == 'x')
				cont += ft_hexa(va_arg(lst, unsigned int));
		}
		else
			cont += ft_putchar(*str);
		str++;
	}
	va_end(lst);
	return (cont);
}
