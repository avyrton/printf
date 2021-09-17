#include "ft_printf.h"

int	funitoax(unsigned long int numero)
{
	char				num[42];
	int					h;
	unsigned long int	uln;

	uln = (unsigned long int)numero;
	h = checkernx(uln);
	num[h + 1] = '\0';
	if (uln == 0)
		num[0] = '0';
	while (uln > 0)
	{
		if ((uln % 16 >= 0) && (uln % 16 <= 9))
		{
			num[h] = ((uln % 16) + '0');
			uln = uln / 16;
			h--;
		}
		else if (uln % 16 > 9)
		{
			num[h] = ((uln % 16) + 87);
			uln = uln / 16;
			h--;
		}
	}
	return (outx(num));
}

int	checkernx(unsigned long wnum)
{
	int	i;

	i = 0;
	while (wnum / 16 > 0)
	{
		i++;
		wnum = wnum / 16;
	}
	return (i);
}

int	funitoau(unsigned int numero)
{
	char	buf[42];
	int		z;
	int		index;

	z = 0;
	if (numero == 0)
		buf[z++] = '0';
	while (numero > 0)
	{
		buf[z++] = (numero % 10) + '0';
		numero /= 10;
	}
	buf[z] = '\0';
	index = 0;
	while (z)
	{
		index++;
		write(1, &buf[--z], 1);
	}
	return (index);
}

int	printu(unsigned int ap)
{
	int	lngt;

	if (ap == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	lngt = funitoau(ap);
	return (lngt);
}
