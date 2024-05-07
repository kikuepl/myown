#include "lib.h"

char	*g_name;
char	*g_hexes;
char	*g_buf;
char	*g_buf_prev;
int		g_check_duplicated;
int		g_cnt;
int		g_hex;
int		g_flag;
int		g_chk_lines;
int		g_bfd;

void	init(void)
{
	g_hexes = "0123456789abcdef";
	g_buf = (char *)malloc(17);
	g_buf_prev = (char *)malloc(17);
	g_check_duplicated = 0;
	g_cnt = 0;
	g_flag = 0;
	g_chk_lines = 0;
	g_bfd = 1;
	g_hex = 0;
}

void	read_stdin(void)
{
	while (read(0, &g_buf[g_cnt], 1))
	{
		if (++g_cnt == 16)
			ft_print();
	}
}

void	read_file(int argc, char **argv, int i, int fd)
{
	i = g_flag;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_err(argv[i], errno);
			continue ;
		}
		while (read(fd, &g_buf[g_cnt], 1))
		{
			g_bfd = 0;
			if (errno)
			{
				ft_err(argv[i], errno);
				break ;
			}
			if (++g_cnt == 16)
				ft_print();
		}
	}
	if (g_bfd)
	{
		ft_err(argv[argc - 1], 9);
	}
}

int	main(int argc, char **argv)
{
	g_name = argv[0];
	init();
	if (2 <= argc && is_option(argv[1]))
		g_flag = 1;
	if (argc <= 1 + g_flag)
		read_stdin();
	else
		read_file(argc, argv, 0, 0);
	if (g_chk_lines)
	{
		if (g_cnt)
		{
			ft_re_print(7, g_hex);
			ft_print_hexes(g_buf, 8 * (g_cnt / 8) + g_cnt);
			ft_print_hexes(g_buf + 8, g_cnt - 8);
			if (g_flag)
				ft_print_mozi(g_buf, g_cnt);
			ft_putchar('\n');
		}
		ft_re_print(7, g_hex + g_cnt);
		ft_putchar('\n');
	}
	free(g_buf);
	return (0);
}
