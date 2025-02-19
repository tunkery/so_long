/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:09:24 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/30 13:59:50 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int count, int i)
{
	long	copy;
	char	number[10];

	copy = n;
	if (copy == 0)
		return (write(1, "0", 1));
	if (copy < 0)
	{
		copy *= -1;
		count = write (1, "-", 1);
		if (count == -1)
			return (count);
	}
	while (copy > 0)
	{
		number[i++] = copy % 10 + 48;
		copy /= 10;
		count++;
	}
	while (i > 0)
	{
		if (write(1, &number[--i], 1) == -1)
			return (-1);
	}
	return (count);
}

int	ft_lowercase_hexs(unsigned long n, int count, int check)
{
	unsigned long	copy;
	char			number[16];
	int				i;

	if (n == 0)
		return (write(1, "0", 1));
	copy = n;
	i = 0;
	while (copy > 0)
	{
		if (copy % 16 >= 10)
			number[i++] = copy % 16 + 'a' - 10;
		else
			number[i++] = copy % 16 + 48;
		copy /= 16;
	}
	while (i > 0)
	{
		check = write (1, &number[--i], 1);
		if (check == -1)
			return (check);
		count += check;
	}
	return (count);
}

int	ft_void(va_list ptr, int count)
{
	void				*ftr;
	unsigned long		l;
	int					temp;

	temp = 0;
	ftr = va_arg(ptr, void *);
	l = (unsigned long) ftr;
	count = write(1, "0", 1);
	if (count == -1)
		return (count);
	count += write(1, "x", 1);
	if (count == 0)
		return (count - 1);
	temp = ft_lowercase_hexs(l, 0, 0);
	if (temp == -1)
		return (temp);
	count += temp;
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n, int count, int check, int i)
{
	unsigned long	copy;
	char			number[10];

	copy = n;
	if (copy == 0)
		return (write(1, "0", 1));
	while (copy > 0)
	{
		number[i++] = copy % 10 + 48;
		copy /= 10;
		count++;
	}
	while (i > 0)
	{
		check = write (1, &number[--i], 1);
		if (check == -1)
			return (check);
	}
	return (count);
}
