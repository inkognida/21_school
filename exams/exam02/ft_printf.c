#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


void	ft_putchar(char c, int *r_b)
{
	write(1, &c, 1);
	*r_b = *r_b + 1;
}

void	ft_puthex(unsigned int h, int *r_b)
{
	char			*base;

	base = "0123456789abcdef";
	if (h >= 16)
		ft_puthex(h / 16, r_b);
	ft_putchar(base[h % 16], r_b);
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
		if (*str == '%' && (*++str == 'x'))
			ft_puthex(va_arg(arg, unsigned int), &r_b);
		if (*str == '\0')
			break ;
		str++;
	}
	va_end(arg);
	return (r_b);
}

int main(void)
{
	int a = ft_printf("aboba %2.5s", "a");
	printf("\n");
	int b = printf("aboba %2.5s", "a");
	printf("\n");
	printf("%d %d\n", a, b);
}
