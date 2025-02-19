/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:05:58 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/30 14:05:15 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digit_print(va_list ptr)
{
	int	n;
	int	count;

	n = va_arg(ptr, int);
	count = ft_putnbr(n, 0, 0);
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_unsigned_print(va_list ptr)
{
	unsigned int	n;

	n = va_arg(ptr, unsigned int);
	return (ft_putnbr_unsigned(n, 0, 0, 0));
}

int	ft_lowercase_hex(va_list ptr, int i, int count, int check)
{
	unsigned int	copy;
	char			number[9];

	copy = va_arg(ptr, unsigned int);
	if (copy == 0)
		return (write(1, "0", 1));
	while (copy > 0)
	{
		if (copy % 16 >= 10)
			number[i++] = copy % 16 + 'a' - 10;
		else
			number[i++] = copy % 16 + 48;
		copy /= 16;
	}
	number[i] = '\0';
	while (i > 0)
	{
		check = write (1, &number[--i], 1);
		if (check == -1)
			return (check);
		count += check;
	}
	return (count);
}

int	ft_uppercase_hex(va_list ptr, int i, int count, int check)
{
	unsigned int	copy;
	char			number[9];

	copy = va_arg(ptr, unsigned int);
	if (copy == 0)
		return (write(1, "0", 1));
	while (copy > 0)
	{
		if (copy % 16 >= 10)
			number[i++] = copy % 16 + 'A' - 10;
		else
			number[i++] = copy % 16 + 48;
		copy /= 16;
	}
	number[i] = '\0';
	while (i > 0)
	{
		check = write(1, &number[--i], 1);
		if (check == -1)
			return (check);
		count += check;
	}
	return (count);
}
