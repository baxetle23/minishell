#include "../includes/minishell.h"

t_env	*ft_find_list_env(char *find, t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strcmp(find, tmp->key))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_get_list_environments(char **e, t_env **env)
{
	int		i;
	t_env	*new;

	i = -1;
	while (e[++i])
	{
		if (!ft_strncmp(e[i], "SHLVL", 5) && e[i][5] == '='
			&& e[i][6] == '1' && e[i][7] == '\0')
			e[i][6] = '2';
		new = ft_lstnew_env(e[i]);
		if (!new)
		{
			ft_lstclear_env(env);
			return (0);
		}
		ft_add_env(env, new);
	}
	new = ft_find_list_env("OLDPWD", env);
	if (new)
	{
		free(new->value);
		new->value = NULL;
	}
	return (1);
}
