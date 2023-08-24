/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:25:13 by marcofer          #+#    #+#             */
/*   Updated: 2023/08/09 15:25:13 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
char	*get_fspec(char *str, char *list_spec)
{
	char *spec_str;


}
*/

void	ft_putptr_pf(void *ptr, char* base, size_t *count)
{
	unsigned long	num;

	ft_putstr_pf("0x", count);
	num = (unsigned long)ptr;	
	if (num < 16)
	{
		ft_putchar_pf(base[num], count);
		return ;
	}
	else
		ft_puthex_ft(num / 16, base, count);
	ft_puthex_ft(num % 16, base, count);
}

void	ft_format(va_list va, char *str, size_t *count)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(va, int), count);
	if (*str == 's')
		ft_putstr_pf(va_arg(va, char*), count);
	if (*str == 'p')
		ft_putptr_pf(va_arg(va, void*), LOW_HEX_BASE, count);		
	if (*str == 'i' || *str == 'd')
		ft_putint_pf(va_arg(va, int), count);
	if (*str == 'x')
		ft_puthex_ft(va_arg(va, int), LOW_HEX_BASE, count);
	if (*str == 'X')
		ft_puthex_ft(va_arg(va, int), UPP_HEX_BASE, count);				
	if (*str == '%')
		ft_putchar_pf(*str, count);
}

int		ft_printf(char const *str, ...)
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

int		main(void)
{
	int				num;
	int				*ptr;
	unsigned long	ptr_address;

	num = 5;
	ptr = &num;
	*ptr = 10;
	ptr_address = (unsigned long)ptr;

	// Specifiers
		// printf("|%-10s|", "left");	// Output: |left      |
		// printf("|%010d|", 42);		// Output: |00042|
		// printf("%.10f", 3.14159);		// Output: 3.14
		// printf("%#x", 42);  // Output: 0x2a
		// printf("This is a literal percent sign: %%\n");
		// printf("String: '%20s'\n", "I'm Kenough");

	// Test
		// ft_printf("\nCharacter 1: '%c' \nCharacter 2: '%c' \nString:'%s' \nPercent : '%%'", '1', '2', "Hi Barbie");
		// ft_printf("\nInteger: '%i'", 223);
		// printf("\nInt = %d", 2147483647);
		// printf("\nInt = %d", 214);
		// ft_printf("\nInt = %d", 2147483647);
		// ft_printf("\nInt = %d", 2147483648);
		// printf("\nhex = %x", 31);
		// ft_printf("\nhex = %x", 31);
		// printf("\nhex = %X", 31);
		// ft_printf("\nhex = %X", 31);		
		printf("\nlong = %lu", ptr_address);
		printf("\nhex = %lx", ptr_address);
		printf("\n&num = %p", ptr);
		ft_printf("\n&num = %p -> ft_printf", ptr);
		// ft_printf("\nnum = %d | &num = %p", num, &num);
	
	printf("\n");
}
