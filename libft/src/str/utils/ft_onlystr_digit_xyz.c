/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlystr_digit_xyz.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:35:18 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 15:35:58 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libs/libft.h"

int	only_digit_xyz(char *split)
{
	int		j;
	char	**str;

	if (!ft_strchr(split, ','))
		return (0);
	j = -1;
	str = ft_split(split, ',');
	if (!str)
		return (0);
	while (str[++j])
	{
		if (!only_digit(str[j]) || j >= 3)
		{
			ft_free_tab(&str, free);
			return (0);
		}
	}
	ft_free_tab(&str, free);
	if (j <= 2)
		return (0);
	return (1);
}
