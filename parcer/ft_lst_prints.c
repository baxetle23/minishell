#include "../includes/minishell.h"

void	ft_print_mas(char **mas)
{
	int	i;

	i = 0;
	if (mas)
	{
		while (mas[i])
			printf("%s\n", mas[i++]);
	}
	else
		printf("doesn't exist\n");
}

void	ft_print_lst_cmds(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		printf("command: %s - active: %i\nflags:\n", tmp->cmd, tmp->active);
		ft_print_mas(tmp->flags);
		printf("args:\n");
		ft_print_mas(tmp->args);
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
