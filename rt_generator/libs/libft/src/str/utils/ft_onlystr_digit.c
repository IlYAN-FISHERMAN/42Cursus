/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlystr_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:34:36 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 15:36:33 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libs/libft.h"

int	only_digit(char *str)
{
	int		nb;
	char	*tmp;

	nb = ft_atoi(str);
	tmp = ft_itoa(nb);
	if (!tmp)
		return (0);
	if (ft_strcmp(str, tmp))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}
