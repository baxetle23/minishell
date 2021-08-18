#include "libft.h"

int	ft_putchar_fd(const char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
