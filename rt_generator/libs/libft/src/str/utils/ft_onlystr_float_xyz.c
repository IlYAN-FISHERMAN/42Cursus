/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlystr_float_xyz.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:36:07 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 15:36:17 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libs/libft.h"

int	only_float_xyz(char *split)
{
	int		j;
	char	**str;

	j = -1;
	if (!ft_strchr(split, ','))
		return (0);
	str = ft_split(split, ',');
	if (!str)
		return (0);
	while (str[++j])
	{
		if (!only_float(str[j]) && !only_digit(str[j]))
		{
			ft_free_tab(&str, free);
			return (0);
		}
	}
	if (j <= 2 || j > 3)
		return (0);
	ft_free_tab(&str, free);
	return (1);
}
