/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:28:49 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/22 11:33:44 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (*envp == 0)
		show_error("Path error");
	return (*envp + 5);
}

void	parse_args(int argc, char **argv, char **envp, t_pipex *pipex)
{
	if (argc != 5)
	{
		print_error("Invalid number of arguments\n");
		exit(1);
	}
	pipex->path = find_path(envp);
	pipex->path_cmd = ft_split(pipex->path, ':');
	pipex->command1 = ft_split(argv[2], ' ');
	pipex->command2 = ft_split(argv[3], ' ');
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	parse_args(argc, argv, envp, &pipex);
	if (pipe(pipex.pipefd) < 0)
		show_error("pipe");
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		show_error("fork");
	if (pipex.pid1 == 0)
		first_child(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		show_error("fork");
	if (pipex.pid2 == 0)
		second_child(pipex, argv, envp);
	close(pipex.pipefd[0]);
	close(pipex.pipefd[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_parent(&pipex);
	return (0);
}
