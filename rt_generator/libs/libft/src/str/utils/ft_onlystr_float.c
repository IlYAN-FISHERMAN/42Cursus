/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlystr_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:34:54 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 15:35:03 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libs/libft.h"

int	only_float(char *str)
{
	int		i;

	i = -1;
	if (!str || str[0] == '.')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i] && str[i] != '.')
		if (!ft_isdigit(str[i]) || !str[i + 1])
			return (0);
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}
