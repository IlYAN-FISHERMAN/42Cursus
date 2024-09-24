/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_gnl_nl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:27:29 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/24 15:28:17 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft.h"

int	correct_gnl_nl(char *gnl)
{
	if (ft_strchr(gnl, '\n'))
		gnl[ft_strlen(gnl) - 1] = '\0';
	return (1);
}
