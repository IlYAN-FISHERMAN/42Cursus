/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:16:13 by ilyanar           #+#    #+#             */
/*   Updated: 2024/02/09 14:12:28 by ilyanar          ###   ########.fr       */
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

typedef struct p_tab
{
	char			**tab;
	struct p_tab	*next;
}	t_tab;

typedef struct p_pipe
{
	int				in_fd;
	int				out_fd;
	int				ac;
	char			**cmd;
	char			**arg;
	char			**env;
	struct p_tab	*next;
}	t_pipe;


#endif
