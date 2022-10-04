/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:46:27 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/18 18:47:02 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	open_infile(char **argv, t_pipex *pipex)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		show_error(argv[1]);
		exit(1);
	}
}

void	open_outfile(char *filename, t_pipex *pipex)
{
	char	*str;

	pipex->outfile = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
	{
		write(2, "/pipex: ", 8);
		print_error(filename);
		str = strerror(errno);
		ft_printf(": %s\n", str);
		exit(1);
	}
}
