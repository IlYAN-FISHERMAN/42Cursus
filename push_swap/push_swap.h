/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:56:47 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/07 17:02:54 by ilyanar          ###   ########.fr       */
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

void	ft_sa_sb(t_listp **stacks, int nb);
void	ft_ss(t_listp **a_stack, t_listp **b_stack);
void	ft_pa_pb(t_listp **a_stack, t_listp **b_stack, int nb);

#endif
