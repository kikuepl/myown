#include "lib.h"

char	*g_name;
char	*g_buf;
int		g_fd;
int		g_buf_size;

void	read_file(int fd)
{
	int	idx;
	int	start;

	if (g_buf_size == 0)
	{
		while (read(fd, g_buf, 1))
			if (errno)
				return ;
	}
	else
	{
		idx = 0;
		while (read(fd, &g_buf[idx % g_buf_size], 1))
		{
			if (errno)
				return ;
			idx++;
		}
		start = idx % g_buf_size;
		if (idx >= g_buf_size)
			write(1, g_buf + start, g_buf_size - start);
		write(1, g_buf, start);
	}
}

void	pre_read(int argc, char **argv)
{
	int	i;
	int	chk;

	i = 2;
	chk = 0;
	while (++i < argc)
	{
		errno = 0;
		g_fd = open(argv[i], O_RDONLY);
		if (g_fd == -1)
		{
			ft_err(argv[i]);
			continue ;
		}
		if (argc > 4)
		{
			if (chk++)
				ft_putstr("\n");
			ft_putstr("==> ");
			ft_putstr(argv[i]);
			ft_putstr(" <==\n");
		}
		read_file(g_fd);
		close(g_fd);
	}
}

int	main(int argc, char **argv)
{
	g_name = argv[0];
	g_buf_size = ft_atoi(argv[2]);
	g_buf = (char *)malloc(sizeof(char) * g_buf_size);
	if (argc == 3)
	{
		read_file(0);
	}
	else
	{
		pre_read(argc, argv);
	}
	free(g_buf);
	return (0);
}
