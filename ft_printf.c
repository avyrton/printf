#include "ft_printf.h"

int 	pars(const char *fmt, va_list ap)
{
	int	lngt;

	lngt = 0;
	if (fmt[0] == '%')
	{
		write(1, "%%", 1);
		lngt++;
	}
	if (fmt[0] == 'p')
		lngt = print_px(va_arg(ap, unsigned long), 'p');
	if (fmt[0] == 'x')
		lngt = print_px(va_arg(ap, unsigned int), 'x');
	if (fmt[0] == 'X')
		lngt = print_X(va_arg(ap, unsigned int), 'X');
	if (fmt[0] == 'u')
		lngt = printu(va_arg(ap, unsigned int));
	if ((fmt[0] == 'i') || (fmt[0] == 'd'))
		lngt = printint(va_arg(ap, int));
	if (fmt[0] == 's')
		lngt = prints(va_arg(ap, char *));
	if (fmt[0] == 'c')
		lngt = printc(va_arg(ap, int));
	return (lngt);
}

int	ft_printf(const char *fmt, ...)
{
	int		z;
	va_list	ap;

	if (!fmt)
		return (-1);
	z = 0;
	va_start (ap, fmt);
	while (*fmt)
	{
		if ((*fmt == '%') && (fmt[1] != '\0'))
		{
			fmt++;
			z = z + pars(fmt, ap);
		}
		else
		{
			write(1, &*fmt, 1);
			z++;
		}
		fmt++;
	}
	va_end(ap);
	return (z);
}

int	print_px(unsigned long int ap, char c)
{
	int	lngt;

	lngt = 0;
	if (c == 'p')
	{
		write (1, "0x", 2);
		lngt += 2;
	}
	if (c == 'p' || c == 'x')
		lngt += funitoax(ap);
	return (lngt);
}
