#include "../includes/minishell.h"

int	ft_strncmp_nr(const char *s1, const char *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	i = 0;
	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	while (i < n)
	{
		if (tmp1[i] != tmp2[i] && tmp1[i] - tmp2[i] != 32
			&& tmp1[i] - tmp2[i] != -32)
			return (tmp1[i] - tmp2[i]);
		if (tmp1[i] == 0 && tmp2[i] == 0)
			return (0);
		i++;
	}
	return (0);
}

int	print_mistake(char *file)
{
	ft_putstr_fd(file, 2);
	ft_putendl_fd(": Permission denied", 2);
	return (-1);
}
