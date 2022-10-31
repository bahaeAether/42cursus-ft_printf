/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:27:11 by baboulou          #+#    #+#             */
/*   Updated: 2022/10/30 17:10:21 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

# include<stdarg.h>
# include<unistd.h>
# include<stdio.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_base_16(unsigned long nb, char *base);
int	ft_putnbr(long n);
int	ft_formatter(va_list ap, char c, int *i);
int	ft_printf(const char *fmt, ...);

#endif
