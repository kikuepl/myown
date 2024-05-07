#include "lib.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_err(char *file)
{
	ft_putstr(basename(g_name));
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str)
	{
		res *= 10;
		res += (*str - '0');
		str++;
	}
	return (res);
}
