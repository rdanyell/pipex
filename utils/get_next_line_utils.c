/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:15:11 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/09 17:00:40 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen_gnl(char *str)
{
	int	n;

	if (!str)
		return (0);
	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char	*pos;
	int		i;

	i = 0;
	pos = (char *)s;
	if (!s)
		return (NULL);
	while (pos[i])
	{
		if (pos [i] == c)
			return (&pos[i]);
		pos++;
	}
	if (c == '\0')
		return (&pos[i]);
	return (NULL);
}
