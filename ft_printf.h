#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int	ft_printf(const char *format, ...);
int	pars(const char *fmt, va_list ap);

int	funitoax(unsigned long int numero);
int	checkernx(unsigned long wnum);
int	outx(char *num);
int	print_px(unsigned long int ap, char c);
int	print_X(unsigned long int ap, char c);
int	funitoa_XP(unsigned long int numero);
int	funitoau(unsigned int numero);
int	ft_itoa(int n);

int	printu(unsigned int ap);
int	funitoau(unsigned int numero);
int	printint(int ap);
int	prints(char *ap);
int	printc(char ap);

#endif
