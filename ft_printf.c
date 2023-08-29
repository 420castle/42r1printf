/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:23:06 by marcofer          #+#    #+#             */
/*   Updated: 2023/08/29 19:24:35 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, char *str, size_t *count)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(va, int), count);
	if (*str == 's')
		ft_putstr_pf(va_arg(va, char *), count);
	if (*str == 'p')
		ft_putptr_pf(va_arg(va, void *), LOW_HEX_BASE, count);
	if (*str == 'i' || *str == 'd')
		ft_putint_pf(va_arg(va, int), count);
	if (*str == 'x')
		ft_puthex_ft(va_arg(va, int), LOW_HEX_BASE, count);
	if (*str == 'X')
		ft_puthex_ft(va_arg(va, int), UPP_HEX_BASE, count);
	if (*str == '%')
		ft_putchar_pf(*str, count);
}

int	ft_printf(char const *str, ...)
{
	va_list		va;
	size_t		count;

	if (!str)
		return (0);
	count = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(va, (char *)str, &count);
		}
		else
			ft_putchar_pf(*str, &count);
		str++;
	}
	va_end(va);
	return (count);
}
