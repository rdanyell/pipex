/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:28:54 by rdanyell          #+#    #+#             */
/*   Updated: 2022/03/22 11:32:58 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdarg.h> 
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_cmds
{
	char	**cmd;
	char	*cmd_args;
}	t_cmds;

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		i;
	char	*path;
	char	**path_cmd;
	int		here_doc;
	int		cmd_num;
	char	*cmd_exec;
	t_cmds	*cmds[100];
}	t_pipex;

void	parse_args(int argc, char **argv, char **envp, t_pipex *pipex);
void	first_child(t_pipex pipex, char **argv, char **envp);
void	second_child(t_pipex pipex, char **argv, char **envp);
void	free_parent(t_pipex *pipex);
void	free_child(t_pipex *pipex);
void	show_error(char *error);
int		print_error(char *error);
void	open_infile(char **argv, t_pipex *pipex);
void	open_outfile(char *filename, t_pipex *pipex);
void	here_doc(char *limiter);

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
char	*ft_strdup(const char *s1);
size_t	ft_putchar_len(char c);
size_t	ft_putstr_len(char *s);
size_t	ft_putnbr_len(int n);
size_t	ft_putnbru_len(unsigned int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif 