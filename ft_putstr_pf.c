/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:36:43 by marcofer          #+#    #+#             */
/*   Updated: 2023/08/24 14:36:43 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pf(char *str, size_t *count)
{
	while (*str != '\0')
	{
		ft_putchar_pf(*str, count);
		str++;
	}	
}