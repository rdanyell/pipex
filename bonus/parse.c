/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:55:56 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/17 13:57:51 by rdanyell         ###   ########.fr       */
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
			break;
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
		i =3;
	while (j < pipex->cmd_num)
	{
		pipex->cmds[j]->cmd_args = argv[i];
		j++;
		i++;
	}
	printf("%s\n", pipex->cmds[j]->cmd_args);
	
}

void	parse_args(int argc, char **argv, char **envp, t_pipex *pipex)
{
	if (argv[1] && !ft_strncmp(argv[1], "here_doc", 9) && argc >=6)
	{
		pipex->here_doc = 1;
		here_doc(argv[2], pipex);
	}
	else if (argc != 5)
	{
		print_error("Invalid number of arguments\n");
		exit(1);
	}
	else
		pipex->here_doc = 0;
	pipex->path = find_path(envp);
	pipex->path_cmd = ft_split(pipex->path, ':');
	pipex->cmd_num = argc - 4 - pipex->here_doc;
	parse_cmds(argv, pipex);
	return ;
}

void	open_infile(char **argv, t_pipex *pipex)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		show_error(argv[1]);
		exit(1);
	}
}

void	open_outfile(char **argv, t_pipex *pipex)
{
	char	*str;

	pipex->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
	{
		write(2, "/pipex: ", 8);
		print_error(argv[4]);
		str = strerror(errno);
		ft_printf(": %s\n", str);
		exit(1);
	}
}
