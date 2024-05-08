#ifndef C10_H
# define C10_H

# include <unistd.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <libgen.h>
# include <errno.h>
# include <string.h>

extern char	*g_name;
extern char	*g_hexes;
extern char	*g_buf;
extern char	*g_buf_prev;
extern int	g_check_duplicated;
extern int	g_cnt;
extern int	g_hex;
extern int	g_flag;
extern int	g_chk_lines;
extern int	g_bfd;

void	ft_err(char *file, int errnum);
void	ft_print_mozi(char *str, int len);
void	ft_print_hexes(char *str, int size);
void	ft_re_print(int n, int hex);
void	ft_print(void);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		is_pirntable(char c);
int		ft_is_equal(char *a, char *b);
int		is_printable(char c);
int		is_option(char *str);

#endif
