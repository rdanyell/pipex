/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:55:56 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/18 18:46:23 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (*envp == 0)
		show_error("Path error");
	return (*envp + 5);
}

void	here_doc(char *limiter, t_pipex *pipex)
{
	int		fd;
	char	*line;

	fd = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		show_error("here_doc");
	line = NULL;
	while (1)
	{
		write(1, "> ", 2);
		if (get_next_line(&line) < 0)
			exit (1);
		if (!ft_strncmp(limiter, line, ft_strlen(limiter) + 1))
			break ;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	close (fd);
	pipex->infile = open("here_doc", O_RDONLY);
	if (pipex->infile < 0)
	{
		unlink("here_doc");
		show_error("here_doc");
		exit(1);
	}
}

void	parse_cmds(char **argv, t_pipex	*pipex)
{
	int	i;
	int	j;

	j = 0;
	i = 2;
	if (pipex->here_doc == 1)
		i = 3;
	pipex->cmds[0] = NULL;
	while (j < pipex->cmd_num)
	{
		pipex->cmds[j] = malloc (sizeof(t_cmds));
		if (!pipex->cmds[j])
			printf("malloc error");
		pipex->cmds[j]->cmd_args = NULL;
		pipex->cmds[j]->cmd_args = ft_strdup(argv[i]);
		pipex->cmds[j]->cmd = ft_split(argv[i], ' ');
		j++;
		i++;
	}
}

void	parse_args(int argc, char **argv, char **envp, t_pipex *pipex)
{
	if (argv[1] && !ft_strncmp(argv[1], "here_doc", 9) && argc >= 6)
	{
		pipex->here_doc = 1;
		here_doc(argv[2], pipex);
	}
	else if (argc < 5)
	{
		print_error("Invalid number of arguments\n");
		exit(1);
	}
	else
		pipex->here_doc = 0;
	pipex->path = find_path(envp);
	pipex->path_cmd = ft_split(pipex->path, ':');
	pipex->cmd_num = argc - 3 - pipex->here_doc;
	parse_cmds(argv, pipex);
	return ;
}
