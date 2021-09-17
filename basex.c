#include "ft_printf.h"

int	outx(char *num)
{
	int	index;

	index = -1;
	while (num[++index])
		write(1, &num[index], 1);
	return (index);
}
