/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:28:55 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/18 17:04:25 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*make_cmd(char **cmd_paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*cmd_paths)
	{
		tmp = ft_strjoin(*cmd_paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		cmd_paths++;
	}
	return (NULL);
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

void	first_child(t_pipex pipex, char **argv, char **envp)
{
	open_infile(argv, &pipex);
	if (dup2(pipex.infile, 0) == -1)
		show_error("dup2 error");
	close(pipex.pipefd[0]);
	dup2(pipex.pipefd[1], 1);
	close(pipex.pipefd[1]);
	if (ft_strncmp(pipex.command1[0], "/", 1) == 0)
	{
		pipex.cmd1 = pipex.command1[0];
		pipex.command1[0] = ft_strrchr(pipex.command1[0], '/');
	}
	else
	{
		pipex.cmd1 = make_cmd(pipex.path_cmd, pipex.command1[0]);
		if (!pipex.cmd1)
		{
			write(2, "/pipex: ", 8);
			write(2, pipex.command1[0], ft_strlen(pipex.command1[0]));
			free_child(pipex);
			print_error(": command not found\n");
			exit(1);
		}
	}
	execve(pipex.cmd1, pipex.command1, envp);
}

void	second_child(t_pipex pipex, char **argv, char **envp)
{
	open_outfile(argv, &pipex);
	if (dup2(pipex.pipefd[0], 0) == -1)
		strerror(errno);
	close(pipex.pipefd[1]);
	dup2(pipex.outfile, 1);
	close(pipex.pipefd[0]);
	if (ft_strncmp(pipex.command2[0], "/", 1) == 0)
	{
		pipex.cmd2 = pipex.command2[0];
		pipex.command2[0] = ft_strrchr(pipex.command2[0], '/');
	}
	else
	{
		pipex.cmd2 = make_cmd(pipex.path_cmd, pipex.command2[0]);
		if (!pipex.cmd2)
		{
			write(2, "/pipex: ", 8);
			write(2, pipex.command2[0], ft_strlen(pipex.command2[0]));
			free_child(pipex);
			print_error(": command not found\n");
			exit(1);
		}
	}
	execve(pipex.cmd2, pipex.command2, envp);
}
