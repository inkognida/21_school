/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:21:37 by hardella          #+#    #+#             */
/*   Updated: 2021/10/17 19:57:44 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	validate(const char *str, va_list *arg, int *r_b)
{
	if (*str == 's')
		ft_putstr(va_arg(*arg, char *), r_b);
	if (*str == 'p')
	{
		ft_putstr("0x", r_b);
		ft_putvoid(va_arg(*arg, unsigned long long int), r_b);
	}
	if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(*arg, int), r_b);
	if (*str == 'u')
		ft_putdnbr(va_arg(*arg, unsigned int), r_b);
	if (*str == 'x')
		ft_puthex(va_arg(*arg, unsigned int), r_b);
	if (*str == 'X')
		ft_puthexup(va_arg(*arg, unsigned int), r_b);
	if (*str == '%')
		ft_putchar('%', r_b);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		r_b;

	r_b = 0;
	str = (char *)str;
	va_start(arg, str);
	while (str)
	{
		while (*str != '%' && *str)
			ft_putchar(*str++, &r_b);
		if (*str == '%' && (*++str == 'c'))
			ft_putchar(va_arg(arg, int), &r_b);
		if (*str == 'd' || *str == 'i' || *str == 'u' || *str == 'x' \
			|| *str == 'X' || *str == '%' || *str == 's' || *str == 'p')
			validate(str, &arg, &r_b);
		if (*str == '\0')
			break ;
		str++;
	}
	va_end(arg);
	return (r_b);
}

//#include <stdio.h>
//int main(void)
//{
//	// char *s = "aboba";
//	int orig = printf("aboba %c\n");
//	// int orig2 = printf("%p\n", s);
//
//	int my = ft_printf("aboba %c\n");
//
//	// printf("\n%p\n", s);
//	// printf("%d %d\n", orig, my);
//	// printf("%d\n", orig);
//	// printf("%d\n", orig2);
//
//
//	printf("%d", orig);
//	printf("%d", my);
//
//
//
//	// printf("\n\n%x", 2147483647);
//	// char *s = "aboba";
//	// printf("%p\n", s);
//
//	return (0);
//}
