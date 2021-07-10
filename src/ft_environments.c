#include "../includes/minishell.h"

t_env	*ft_get_list_env(char *find, t_env **env)
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
		new = ft_lstnew_env(e[i]);
		if (!new)
		{
			ft_lstclear_env(env);
			return (0);
		}
		ft_add_env(env, new);
	}

	new = ft_get_list_env("OLDPWD", env);
	if (new)
		new->value = NULL;
	new = *env;
	while (new)
	{
		printf("%s", new->key);
		if (new->value)
			printf("=%s\n",new->value);
		else
			printf("\n");
		new = new->next;
	}


	return (1);

}
