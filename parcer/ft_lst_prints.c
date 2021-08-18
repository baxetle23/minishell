#include "../includes/minishell.h"

void	ft_print_lst_cmds(t_cmd **cmd)
{
	t_cmd	*tmp;
	int		i;

	tmp = *cmd;
	while (tmp)
	{
		printf("command: %s - active: %i\nflags:\n", tmp->cmd, tmp->active);
		i = 0;
		if (tmp->flags)
		{
			while (tmp->flags[i])
				printf("-%s-\n", tmp->flags[i++]);
		}
		else
			printf("flags doesn't exist\n");
		printf("args:\n");
		i = 0;
		if (tmp->args)
		{
			while (tmp->args[i])
				printf("%s\n", tmp->args[i++]);
		}
		else
			printf("args doesn't exist\n");
		printf("//end//\n");
		tmp = tmp->next;
	}
}

void	ft_print_lst_words(t_words **words)
{
	t_words	*tmp;

	tmp = *words;
	while (tmp)
	{
		printf("%s| %d\n", tmp->word, tmp->active);
		tmp = tmp->next;
	}
}

void	ft_print_lst_env(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}
