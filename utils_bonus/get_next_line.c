/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:21:44 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/18 18:41:28 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	get_next_line(char **line)
{
	int		result;
	int		i;
	char	*buffer;

	result = 0;
	i = 0;
	buffer = malloc(100000);
	if (!buffer)
		return (0);
	*line = buffer;
	result = read(0, &buffer[i], 1);
	while (result > 0 && buffer[i] != '\n')
	{	
		i++;
		result = read(0, &buffer[i], 1);
	}
	buffer[i] = '\0';
	return (result);
}
