/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invsqrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:05:11 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/08 10:05:20 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

float	ft_invsqrt(float n)
{
	float	half_n;
	int		i;
	float	x;

	half_n = n * 0.5f;
	i = *(int *)&n;
	i = 0x5f3759df - (i >> 1);
	x = *(float *)&i;
	x = x * (1.5f - (half_n * x * x));
	return (x);
}

float	ft_invsqrt_iter(float n, int iter)
{
	float	half_n;
	int		i;
	float	x;

	half_n = n * 0.5f;
	i = *(int *)&n;
	i = 0x5f3759df - (i >> 1);
	x = *(float *)&i;
	while (iter--)
		x = x * (1.5f - (half_n * x * x));
	return (x);
}
