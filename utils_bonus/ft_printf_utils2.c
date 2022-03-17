/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:06:09 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/17 13:43:24 by rdanyell         ###   ########.fr       */
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
