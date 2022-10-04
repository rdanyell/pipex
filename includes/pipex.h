/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:28:54 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/09 17:02:45 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h> 
# include <string.h>
# include <stdarg.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	char	*path;
	char	**path_cmd;
	char	**command1;
	char	**command2;
	char	*cmd1;
	char	*cmd2;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

void	first_child(t_pipex pipex, char **argv, char **envp);
void	second_child(t_pipex pipex, char **argv, char **envp);
void	free_parent(t_pipex *pipex);
void	free_child(t_pipex pipex);
void	show_error(char *error);
int		print_error(char *error);

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp( const char *s1, const char *s2, size_t n );
int		ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
int		get_next_line(char **line);
int		ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(const char *s, int c);
size_t	ft_putchar_len(char c);
size_t	ft_putstr_len(char *s);
size_t	ft_putnbr_len(int n);
size_t	ft_putnbru_len(unsigned int n);

#endif 