/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:25:54 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/16 17:27:34 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void redirect(char argv[2], envp, pipex.infile);

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	parse_args(argc, argv, envp, &pipex);
	open_infile(argv, &pipex);
	open_outfile(argv, &pipex);
	dup2(pipex.infile, 0);
	dup2(pipex.outfile, 1);
	//redirect(argv[2], envp, pipex.infile);
	return (0);
}