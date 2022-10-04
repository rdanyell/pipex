/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:47:37 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/21 14:21:12 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, int sign)
{
	int					i;
	unsigned long int	nb;

	i = 0;
	nb = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		ft_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i++] - '0');
	}
	if (str[i])
		ft_error();
	if ((nb > 2147483647) && (sign == 1))
		ft_error();
	if ((nb > 2147483648) && (sign == -1))
		ft_error();
	free(str);
	return ((int)(nb * sign));
}

int	ft_atoi_ps(const char *str)
{
	int		i;
	int		len;
	int		sign;
	char	*line;

	sign = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	len = ft_strlen(str);
	line = ft_substr(str, i, len - i);
	return (ft_atoi(line, sign));
}
