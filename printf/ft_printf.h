/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 02:16:42 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/22 13:54:33 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	printf_base_addr(unsigned long long int nb, char *base, int *n);
void	stlen(char *tab, int *nb, char c, const char *str);
void	ft_putchar(char c, int *nb);
void	ft_putnbr(int nb, int *n);

int		who_is_char(const char *str, va_list *args, int *nb);
int		ft_printf(const char *str, ...);

#endif
