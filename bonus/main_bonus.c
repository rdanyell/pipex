/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:25:54 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/18 18:37:36 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	get_cmd(t_pipex *pipex)
{
	int	i;
	printf("HELLO GET_CMD");

	i = pipex->i;
	if (ft_strncmp(pipex->cmds[i]->cmd_args, "/", 1) == 0)
	{
		pipex->cmd_exec = pipex->cmds[i]->cmd[0];
		pipex->cmds[i]->cmd[0] = ft_strrchr(pipex->cmds[i]->cmd[0], '/');
	}
	else 
	{
		pipex->cmd_exec = make_cmd(pipex->path_cmd, pipex->cmds[i]->cmd[0]);
		if(!pipex->cmd_exec)
		{
			write(2, "/pipex: ", 8);
			write(2, pipex->cmds[i]->cmd[0], ft_strlen(pipex->cmds[i]->cmd[0]));
			free_child(pipex);
			print_error(": command not found\n");
			exit(1);
		}

	}
}

void	exec_cmd(t_pipex *pipex, char **envp)
{
	int	i;
	
	i = pipex->i;
	if (ft_strncmp(pipex->cmds[i]->cmd_args, "/", 1) == 0)
	{
		pipex->cmd_exec = pipex->cmds[i]->cmd[0];
		pipex->cmds[i]->cmd[0] = ft_strrchr(pipex->cmds[i]->cmd[0], '/');
	}
	else 
	{
		pipex->cmd_exec = make_cmd(pipex->path_cmd, pipex->cmds[i]->cmd[0]);
		if(!pipex->cmd_exec)
		{
			write(2, "/pipex: ", 8);
			write(2, pipex->cmds[i]->cmd[0], ft_strlen(pipex->cmds[i]->cmd[0]));
			free_child(pipex);
			print_error(": command not found\n");
			exit(1);
		}

	}
	execve(pipex->cmd_exec, pipex->cmds[i]->cmd, envp);
	printf("Execve error");
}

void redirect(t_pipex *pipex, char **envp)
{
	pid_t	pid;
	int		pipefd[2];
	int		i;
	
	i = pipex->i;
	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		waitpid(pid, NULL, 0);
	}
	else 
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		// get_cmd(pipex);
		// execve(pipex->cmd_exec, pipex->cmds[i]->cmd, envp);
		printf("EXECVE ERROR");
		exec_cmd(pipex, envp);
	}
	
	//get_cmd(pipex);
}


int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	
	pipex.i = 0;
	parse_args(argc, argv, envp, &pipex);
	open_infile(argv, &pipex);
	open_outfile(argv[argc-1], &pipex);
	dup2(pipex.infile, 0);
	redirect(&pipex, envp);
	pipex.i++;
	while (pipex.i < pipex.cmd_num - 1)
	{
			redirect(&pipex, envp);
			pipex.i++;
	}
	get_cmd(&pipex);
	dup2(pipex.outfile, 1);
	execve(pipex.cmd_exec, pipex.cmds[pipex.i]->cmd, envp);
	return (0);
}