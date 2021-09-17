#include "ft_printf.h"

int	print_X(unsigned long int ap, char c)
{
	int	lngt;

	lngt = 0;
	if (c == 'X')
		lngt = lngt + funitoa_XP(ap);
	return (lngt);
}

int	funitoa_XP(unsigned long int numero)
{
	unsigned long int	uln;
	char				num[42];
	int					j;

	uln = (unsigned long int)numero;
	j = checkernx(uln);
	num[j + 1] = '\0';
	if (uln == 0)
		num[0] = '0';
	while (uln > 0)
	{
		if ((uln % 16 >= 0) && (uln % 16 <= 9))
		{
			num[j] = ((uln % 16) + '0');
			uln /= 16;
			j--;
		}
		else if (uln % 16 > 9)
		{
			num[j] = ((uln % 16) + 55);
			uln = uln / 16;
			j--;
		}
	}
	return (outx(num));
}
