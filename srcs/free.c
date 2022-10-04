/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:28:55 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/09 12:36:43 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_child(t_pipex pipex)
{
	int	i;

	i = 0;
	close(pipex.infile);
	close(pipex.outfile);
	while (pipex.path_cmd[i])
	{
		free(pipex.path_cmd[i]);
		i++;
	}
	free(pipex.path_cmd);
}

void	free_parent(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->path_cmd[i])
	{
		free(pipex->path_cmd[i]);
		i++;
	}
	i = 0;
	while (pipex->command1[i])
	{
		free(pipex->command1[i]);
		i++;
	}
	i = 0;
	while (pipex->command2[i])
	{
		free(pipex->command2[i]);
		i++;
	}
	free(pipex->path_cmd);
	free(pipex->command1);
	free(pipex->command2);
}
