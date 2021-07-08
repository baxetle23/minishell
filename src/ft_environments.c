#include "../includes/minishell.h"

int	ft_get_list_environments(char **e, t_env **env)
{
	int		i;
	t_env	*new;

	i = -1;
	while (e[++i])
	{
		new = ft_lstnew_env(e[i]);
		if (!new)
		{
			ft_lstclear_env(env);
			return (0);
		}
		ft_add_env(env, new);
	}
	return (1);
}
