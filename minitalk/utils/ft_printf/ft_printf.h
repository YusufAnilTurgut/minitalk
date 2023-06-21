/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:56:14 by yturgut           #+#    #+#             */
/*   Updated: 2023/02/13 14:20:28 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdarg.h>
# include	<stdlib.h>
# include	<unistd.h>

int		ft_printf(const char *str, ...);
int		ft_findpercentsign(va_list args, const char *str);
int		ft_findformat(va_list args, const char c);
int		ft_putchar(char c);
int		ft_printstr(char *a);
int		ft_printnbr(int a);
int		ft_printnumber(unsigned int a, const char format);
int		ft_turnhex_ptr(unsigned int a, char format);
int		ft_hex_len(unsigned long num);
int		ft_int_len(long nb);
int		ft_print_ptr(unsigned long num, char format);
char	*ft_int_to_asci(long nb, size_t count, int flag);
char	*ft_itoa(long n);
void	ft_print_hex(unsigned long num, char format);

#endif