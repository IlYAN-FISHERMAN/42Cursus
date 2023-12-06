/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:56:47 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/06 17:07:07 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_listp
{
	int				i;
	int				nb;
	int				check;
	int				content;
	struct s_listp	*next;
	struct s_listp	*previous;
}	t_listp;

#endif
