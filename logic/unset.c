#include "../includes/minishell.h"

void	ft_delete_list_env(char *key, t_env **env)
{
	t_env *tmp;
	t_env *tmp_2;

	tmp = *env;
	while(tmp)
	{
		if (!ft_strcmp(tmp->next->key, key))
		{
			printf("%s\n", key);
			printf("%s\n", tmp->next->key);
			if (tmp->next->key)
				free(tmp->next->key);
			if (tmp->next->value)
				free(tmp->next->value);
			tmp_2 = tmp->next->next;
			free(tmp->next);
			tmp->next = tmp_2;
			return ;
		}
		tmp = tmp->next;
	}
}

int	comand_unset(t_cmd *cmd, t_env *envp)
{
	int	i;

	i = 0;
	while (cmd->args[i])
	{	
		if (ft_find_list_env(cmd->args[i], &envp))
			ft_delete_list_env(cmd->args[i], &envp);
		i++;
	}
	return (0);
}