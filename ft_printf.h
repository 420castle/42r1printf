/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:48:09 by marcofer          #+#    #+#             */
/*   Updated: 2023/08/09 17:48:09 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

# define FSPEC "cspdiuxX%"
# define UPP_HEX_BASE "0123456789ABCDEF"
# define LOW_HEX_BASE "0123456789abcdef"

void	ft_putchar_pf(char c, size_t *count);
void	ft_putint_pf(int num, size_t *count);
void	ft_puthex_ft(int num, char *base, size_t *count);
void	ft_putstr_pf(char *str, size_t *count);
void	ft_putptr_pf(void *ptr, char *base, size_t *count);
int		ft_printf(char const *str, ...);

#endif