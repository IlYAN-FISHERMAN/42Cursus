/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:16:46 by ilyanar           #+#    #+#             */
/*   Updated: 2023/12/02 18:27:55 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	push_swap(char **av)
{
	int	i;

	i = ft_atoi(av[1]);
	ft_printf("%d", i);
}

int	main(int ac, char **av)
{
	if (ac > 2)
		push_swap(av);
}
