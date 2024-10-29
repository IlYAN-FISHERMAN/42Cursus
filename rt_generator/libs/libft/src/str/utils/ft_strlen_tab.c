/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:53:22 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 15:53:25 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libs/libft.h"

int	ft_strlen_tab(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str && str[++i])
		;
	return (i);
}
