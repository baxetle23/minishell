#include "../includes/minishell.h"

void	ft_lstclear_cmds(t_cmd **env)
{
	t_cmd	*tmp;
	t_cmd	*cur;

	tmp = *env;
	while (tmp)
	{
		cur = tmp;
		tmp = tmp->next;
		if (cur->cmd)
			free(cur->cmd);
		if (cur->flags)
			ft_free_mas(cur->flags);
		if (cur->args)
			ft_free_mas(cur->args);
		free(cur);
		cur = NULL;
	}
}

void	ft_lstclear_env(t_env **env)
{
	t_env	*tmp;
	t_env	*cur;

	tmp = *env;
	while (tmp)
	{
		cur = tmp;
		tmp = tmp->next;
		free(cur->key);
		free(cur->value);
		free(cur);
	}
}

void	ft_lstclear_words(t_words **env)
{
	t_words	*tmp;
	t_words	*cur;

	tmp = *env;
	while (tmp)
	{
		cur = tmp;
		tmp = tmp->next;
		free(cur->word);
		free(cur);
	}
}
