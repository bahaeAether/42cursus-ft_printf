/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:24:54 by baboulou          #+#    #+#             */
/*   Updated: 2022/10/30 17:17:37 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatter(va_list ap, char c, int *i)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'X')
		count += ft_putnbr_base_16(va_arg(ap, unsigned int), HEX_UPPER);
	else if (c == 'x')
		count += ft_putnbr_base_16(va_arg(ap, unsigned int), HEX_LOWER);
	else if (c == 'p')
		count += ft_putstr("0x") + ft_putnbr_base_16(va_arg(ap, unsigned long),
				HEX_LOWER);
	else if (c == 'u')
		count += ft_putnbr(va_arg(ap, unsigned int));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == '%')
		count += ft_putchar('%');
	else
		(*i)--;
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, fmt);
	i = -1;
	count = 0;
	while (fmt[++i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (!fmt[i])
				return (count);
			count += ft_formatter(ap, fmt[i], &i);
		}
		else
			count += ft_putchar(fmt[i]);
	}
	va_end(ap);
	return (count);
}
