#include "lib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	is_printable(char c)
{
	return (' ' <= c && c <= '~');
}

int	is_option(char *str)
{
	return (str[0] == '-' && str[1] == 'C');
}

int	ft_is_equal(char *a, char *b)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}
