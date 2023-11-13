/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 02:16:42 by ilyanar           #+#    #+#             */
/*   Updated: 2023/11/12 21:26:01 by ilyanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	stlen(char *tab, int *nb);
void	ft_putchar(char c, int *nb);
void	ft_putnbr(long nb, int *n);
void	putnbr_base(size_t nb, char *base, int *n);
void	print_0x(unsigned long long int nb, char *base, int *n);
void	printf_addr(unsigned long long int nb, char *base, int *n);

int		check(const char *str);
void	who_is_char(const char *str, va_list *args, int *nb);
int		ft_printf(const char *str, ...);

#endif
