#include "lib.h"

void	ft_err(char *file, int errnum)
{
	errno = errnum;
	ft_putstr(basename(g_name));
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	errno = 0;
}

void	ft_print_mozi(char *str, int len)
{
	int	i;

	i = 0;
	ft_putstr("  |");
	while (i < len)
	{
		if (is_printable(str[i]))
		{
			ft_putchar(str[i]);
		}
		else
		{
			ft_putchar('.');
		}
		i++;
	}
	ft_putchar('|');
}

void	ft_print_hexes(char *str, int size)
{
	int	i;
	int	kazu;

	i = 0;
	if (g_flag)
	{
		ft_putchar(' ');
	}
	while (i < size && i < 8)
	{
		ft_putchar(' ');
		kazu = str[i];
		ft_putchar(g_hexes[kazu / 16]);
		ft_putchar(g_hexes[kazu % 16]);
		i++;
	}
	while (i < 8)
	{
		ft_putstr("   ");
		i++;
	}
}

void	ft_re_print(int n, int hex)
{
	if (!hex)
	{
		n += g_flag;
		while (n--)
		{
			ft_putchar('0');
		}
		return ;
	}
	ft_re_print(n - 1, hex / 16);
	ft_putchar(g_hexes[hex % 16]);
}

void	ft_print(void)
{
	g_chk_lines = 1;
	if (ft_is_equal(g_buf, g_buf_prev))
	{
		if (!g_check_duplicated)
		{
			g_check_duplicated = 1;
			ft_putstr("*\n");
		}
	}
	else
	{
		g_check_duplicated = 0;
		ft_re_print(7, g_hex);
		ft_print_hexes(g_buf, 8 * (g_cnt / 8) + g_cnt);
		ft_print_hexes(g_buf + 8, g_cnt - 8);
		if (g_flag)
			ft_print_mozi(g_buf, g_cnt);
		ft_putchar('\n');
		free(g_buf_prev);
		g_buf_prev = g_buf;
		g_buf = (char *)malloc(17);
	}
	g_hex += 16;
	g_cnt = 0;
}
