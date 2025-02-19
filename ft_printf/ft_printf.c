/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:07:14 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/15 19:05:23 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		count;
	int		check;

	count = 0;
	check = 0;
	va_start(ptr, format);
	while (*format && count != -1)
	{
		if (*format == '%')
		{
			format++;
			count = ft_flag_checker(ptr, *format, format, 0);
			check += count;
		}
		else
		{
			count = ft_word_print(*format);
			check += count;
		}
		format++;
	}
	return (va_end(ptr), check);
}

// #include <limits.h>

// int main()
// {
// 	int	i;
// 	int	s;

// 	i = ft_printf("%x", LONG_MIN);
// 	ft_printf("\n%d\n", i);
// 	s = printf("%lx", LONG_MIN);
// 	printf("\n%d", s);
// 	return (0);
// }
// int main()
// {
// 	// int i;
// 	int s;

// 	// i = printf("dgs%dxx", 10);
// 	// printf("\n%d\n", i);
// 	s = ft_printf(" %%");
// 	ft_printf("\n%d", s);
// 	return (0);
// }