/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:08:26 by marcofer          #+#    #+#             */
/*   Updated: 2023/08/24 14:08:26 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char c, size_t *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putint_pf(int num, size_t *count)
{
	if (num == -2147483648)
	{
		ft_putchar_pf('-', count);
		ft_putchar_pf('2', count);
		num = 147483648;
	}
	if (num < 0)
	{
		ft_putchar_pf('-', count);
		num *= -1;
	}
	if (num < 10)
	{
		ft_putchar_pf(num + '0', count);
		return ;
	}
	else
		ft_putint_pf(num / 10, count);
	ft_putint_pf(num % 10, count);
}

void	ft_puthex_ft(int num, char *base, size_t *count)
{
	if (num < 0)
	{
		ft_putchar_pf('-', count);
		num *= -1;
	}
	if (num < 16)
	{
		ft_putchar_pf(base[num], count);
		return ;
	}
	else
		ft_puthex_ft(num / 16, base, count);
	ft_puthex_ft(num % 16, base, count);
}
