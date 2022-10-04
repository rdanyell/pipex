/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:47:44 by rdanyell          #+#    #+#             */
/*   Updated: 2021/10/27 11:13:02 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len ++;
	while (n)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	length;
	char	*res;
	long	nb;

	length = get_len(n);
	nb = n;
	res = (char *)malloc(length + 1);
	if (!res)
		return (NULL);
	res [length--] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		res[0] = '0';
	while (nb)
	{
		res[length] = '0' + nb % 10;
		nb = nb / 10;
		length--;
	}
	return (res);
}
