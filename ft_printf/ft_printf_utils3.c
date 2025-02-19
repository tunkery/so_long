/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:58:53 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/30 13:30:54 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_checker(va_list ptr, char c, const char *format, int count)
{
	if (c == 'c' || c == 's')
		count = ft_string_char(ptr, format, 0);
	else if (c == 'p')
		count = ft_void(ptr, 0);
	else if (c == 'i' || c == 'd')
		count = ft_digit_print(ptr);
	else if (c == 'u')
		count = ft_unsigned_print(ptr);
	else if (c == 'x')
		count = ft_lowercase_hex(ptr, 0, 0, 0);
	else if (c == 'X')
		count = ft_uppercase_hex(ptr, 0, 0, 0);
	else if (c == '%')
		count = write(1, "%", 1);
	else
		return (-1);
	return (count);
}

int	ft_word_print(char c)
{
	return (write(1, &c, 1));
}

int	ft_string_char(va_list ptr, const char *format, int i)
{
	char	*s;
	char	c;
	int		count;

	if (*format == 'c')
	{
		c = va_arg(ptr, int);
		count = write(1, &c, 1);
		if (count == -1)
			return (count);
		i++;
	}
	else if (*format == 's')
	{
		s = va_arg(ptr, char *);
		if (s == NULL)
			return (write(1, "(null)", 6));
		while (s[i] && s)
		{
			count = write(1, &s[i++], 1);
			if (count == -1)
				return (count);
		}
	}
	return (i);
}
