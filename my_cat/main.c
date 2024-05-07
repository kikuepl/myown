#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

#define BUF_SIZE 30720

char	*g_name;

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
	errno = 0;
}

void	read_file(int fd, char *file)
{
	char	buf[BUF_SIZE];
	int		read_bytes;

	read_bytes = read(fd, buf, BUF_SIZE);
	while (read_bytes)
	{
		if (errno)
		{
			ft_err(file);
			return ;
		}
		write(1, buf, read_bytes);
		read_bytes = read(fd, buf, BUF_SIZE);
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	int	fd;
	int	i;

	g_name = argv[0];
	if (argc == 1)
		read_file(0, 0);
	else
	{
		i = 0;
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == -1)
			{
				ft_err(argv[i]);
				continue ;
			}
			read_file(fd, argv[i]);
		}
	}
	return (0);
}
