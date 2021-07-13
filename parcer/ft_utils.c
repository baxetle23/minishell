#include "../includes/minishell.h"

void	ft_free_mas(char **t)
{
	int	i;

	if (!t)
		return;
	i = 0;
	while (t[i] != NULL)
		free(t[i++]);
	free(t);
}

void	ft_terminate(char *s)
{
	ft_putstr_fd(s, 2);
	exit (1);
}
