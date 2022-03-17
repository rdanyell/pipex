/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:18:48 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/17 13:43:30 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

size_t	ft_putnbrhex_low(unsigned long n)

{
	static size_t	i;
	const char		base[] = "0123456789abcdef";

	i = 0;
	while (n >= 16)
	{
		ft_putnbrhex_low(n / 16);
		break ;
	}
	i += ft_putchar_len(base[n % 16]);
	return (i);
}

size_t	ft_putnbrhex_high(unsigned long n)

{
	static size_t	i;
	const char		base[] = "0123456789ABCDEF";

	i = 0;
	while (n >= 16)
	{
		ft_putnbrhex_high(n / 16);
		break ;
	}
	i += ft_putchar_len(base[n % 16]);
	return (i);
}

size_t	ft_pointer(unsigned long p)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	i += ft_putstr_len("0x");
	j += ft_putnbrhex_low(p);
	return (i + j);
}

size_t	ft_print_arg(const char *str, va_list ap, size_t i)
{
	if (str[i] == 'c')
		return (ft_putchar_len((char)va_arg(ap, int)));
	if (str[i] == 's')
		return (ft_putstr_len(va_arg(ap, char *)));
	if (str[i] == 'p')
		return (ft_pointer(va_arg(ap, unsigned long long)));
	if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr_len(va_arg(ap, int)));
	if (str[i] == 'u')
		return (ft_putnbru_len(va_arg(ap, unsigned int)));
	if (str[i] == 'x')
		return (ft_putnbrhex_low(va_arg(ap, unsigned int )));
	if (str[i] == 'X')
		return (ft_putnbrhex_high(va_arg(ap, unsigned int )));
	if (str[i] == '%')
		return (ft_putchar_len('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t	counter;
	size_t	i;
	va_list	ap;

	counter = 0;
	i = 0;
	va_start(ap, str);
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			counter += ft_print_arg(str, ap, ++i);
		}
		else
		{
			write (1, &str[i], 1);
			counter++;
		}
		i++;
	}
	va_end(ap);
	return (counter);
}
