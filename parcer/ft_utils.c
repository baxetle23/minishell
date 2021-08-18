#include "../includes/minishell.h"

void	ft_free_mas(char **t)
{
	int	i;

	if (!t)
		return ;
	i = 0;
	while (t[i] != NULL)
		free(t[i++]);
	free(t);
}

char	**get_empty_m(void)
{
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *));
	tmp[0] = NULL;
	return (tmp);
}

void	ft_terminate(char *s)
{
	ft_putstr_fd(s, 2);
	exit (1);
}

void	ft_remove_files(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		if (tmp->cmd[0] == '<')
		{
			if (!ft_strncmp(tmp->args[0], FILENAME, ft_strlen(FILENAME)))
			{
				printf("\nfile: %s\n", tmp->args[0]);
				unlink(tmp->args[0]);
			}
		}
		tmp = tmp->next;
	}
}
