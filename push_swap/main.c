/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:57:17 by ilyanar           #+#    #+#             */
/*   Updated: 2024/01/05 00:58:32 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		if ((push_swap(av, ac)) == -1)
		{
			ft_printf("Error");
			return (-1);
		}
	}
	return (0);
}
