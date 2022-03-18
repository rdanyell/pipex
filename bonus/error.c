/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:29:38 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/18 18:42:08 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	print_error(char *error)
{
	write(2, error, ft_strlen(error));
	return (1);
}

void	show_error(char *error)
{
	write(2, "/pipex: ", 8);
	perror(error);
	exit (1);
}
