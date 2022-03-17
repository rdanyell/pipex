/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:51:09 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/17 13:43:19 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

size_t	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr_len(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_putnbr_len(int n)
{
	long	nbr;
	size_t	i;

	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		i += ft_putchar_len('-');
		nbr = nbr * -1;
	}
	while (nbr >= 10)
	{
		i += ft_putnbr_len(nbr / 10);
		break ;
	}
	i += ft_putchar_len((char)(nbr % 10 + '0'));
	return (i);
}

size_t	ft_putnbru_len(unsigned int n)
{
	size_t			i;
	unsigned int	nbr;

	i = 0;
	nbr = n;
	while (nbr >= 10)
	{
		i += ft_putnbru_len(nbr / 10);
		break ;
	}
	i += ft_putchar_len((char)(nbr % 10 + '0'));
	return (i);
}
