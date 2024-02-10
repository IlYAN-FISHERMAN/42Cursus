/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:16:13 by ilyanar           #+#    #+#             */
/*   Updated: 2024/02/10 15:19:35 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/fcntl.h>
# include <sys/unistd.h>
# include <sys/wait.h>
# include <unistd.h>

# define PATH "PATH"

typedef struct p_pipex
{
	int		pipes1[2];
	int		pipes2[2];
	int		in_fd;
	int		out_fd;
	pid_t	f_pid;
	char	*path;
	char	*cmd_alone;
	char	**arg;
	char	**env;
}	t_pipe;

int		free_tab(char **tab);
int		ft_count_tab(char *av);
int		is_limiter(char	*line, char *limiter);
int		last_exec(char *path, char **env, char **cmd, char *file);
int		is_string(char *av, char *str);

char	*join_cmd_path(char *av, char *env);
char	**new_av(char **av, int ac);
char	**ft_cmd_arg(char *av);
char	*strchr_path_line(char **env);

void	ft_first_child(char *path, char **env, char **cmd, int *pipes);
void	path_command(char *av, t_pipe *t_main);
void	init_path(t_pipe *t_main, char **env);
void	fabien(char **env, t_pipe *t_main, int	*pipes);
void	ft_strerror(char *tab, int cmd, char *av, t_pipe *t_main);
void	print_double_array(char **tab);
void	found_cmd_alone(t_pipe *t_main, char *av);
void	parse_arg(t_pipe *t_main, char *av);
void	ft_free_char(t_pipe *t_main, int cmd);
void	pipex(char **av, char **envp, int fd);

#endif
