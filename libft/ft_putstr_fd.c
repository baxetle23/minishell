

#include "libft.h"

int	ft_putstr_fd(const char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	return (-1);
}

