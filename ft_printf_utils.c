/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:17:23 by baboulou          #+#    #+#             */
/*   Updated: 2022/10/30 01:24:27 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	count = 0;
	if (!str)
		return (write(1, &"(null)", 6));
	i = -1;
	while (str[++i])
	{
		count += ft_putchar(str[i]);
	}
	return (count);
}

int	ft_putnbr_base_16(unsigned long nb, char *base)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += ft_putnbr_base_16(nb / 16, base);
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count += write(1, "-", 1);
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + 48);
	return (count);
}
