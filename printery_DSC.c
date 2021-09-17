#include "ft_printf.h"

static int	numcheck(int numero)
{
	if (numero == 0)
	{
		write(1, "0", 1);
		return (2);
	}
	if (numero == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (12);
	}
	if (numero < 0)
	{
		write(1, "-", 1);
		numero = numero * -1;
		return (1);
	}
	return (0);
}

int 	ft_itoa(int n)
{
	int		index;
	int		j;
	char	num[42];

	index = 0;
	j = numcheck(n);
	if (j == 2 || j == 12)
		return (j - 1);
	if (j == 1)
		n = n * -1;
	while (n > 0)
	{
		num[index] = (n % 10) + '0';
		n /= 10;
		index++;
	}
	while (index-- > 0)
	{
		write(1, &num[index], 1);
		j++;
	}
	return (j);
}

int	printint(int ap)
{
	int	lngt;

	lngt = ft_itoa(ap);
	return (lngt);
}

int	prints(char *ap)
{
	int	lngt;

	lngt = 0;
	if (ap == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*ap)
	{
		write (1, &ap[0], 1);
		ap++;
		lngt++;
	}
	return (lngt);
}

int	printc(char ap)
{
	write(1, &ap, 1);
	return (1);
}
