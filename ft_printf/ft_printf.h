/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:09:31 by bolcay            #+#    #+#             */
/*   Updated: 2024/11/29 22:34:53 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr(int n, int count, int i);
int		ft_digit_print(va_list ptr);
int		ft_lowercase_hex(va_list ptr, int i, int count, int check);
int		ft_uppercase_hex(va_list ptr, int i, int count, int check);
int		ft_lowercase_hexs(unsigned long n, int count, int check);
int		ft_void(va_list ptr, int count);
int		ft_putnbr_unsigned(unsigned int n, int count, int check, int i);
int		ft_unsigned_print(va_list ptr);
int		ft_flag_checker(va_list ptr, char c, const char *format, int count);
int		ft_string_char(va_list ptr, const char *format, int i);
int		ft_word_print(char c);
#endif