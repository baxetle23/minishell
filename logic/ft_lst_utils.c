#include "../includes/minishell.h"

t_env	*find_list_envp(const char *key, t_env *envp)
{
	t_env	*tmp;

	tmp = envp;
	while (tmp)
	{
		if (!ft_strncmp(key, tmp->key, ft_strlen(key)
				&& ft_strlen(key) == ft_strlen(tmp->key)))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
