#include "../includes/minishell.h"

void	ft_found_new_red(t_words *tmp, t_cmd **start_cmd, int start)
{
	t_cmd	*cmd;
	char	**args;

	if ((tmp->word[0] == '>' || tmp->word[0] == '<') && tmp->active)
	{
		if (tmp->next && !(tmp->next->active))
		{
			args = (char **)malloc(sizeof(char **) * 2);
			args[0] = ft_strdup(tmp->next->word);
			args[1] = NULL;
			cmd = ft_lstnew_cmd(ft_strdup(tmp->word), get_empty_m(), args, 1);
			start = start + 1;
			tmp = tmp->next;
		}
		else
			cmd = ft_lstnew_cmd(ft_strdup(tmp->word), get_empty_m(),
					get_empty_m(), 1);
		ft_lstadd_cmd(start_cmd, cmd);
	}
}

void	ft_add_all_redirects(t_words **words, int start, t_cmd **start_cmd)
{
	t_words	*tmp;

	tmp = *words;
	while (start--)
		tmp = tmp->next;
	while (tmp && !(tmp->word[0] == '|' && tmp->active))
	{
		ft_found_new_red(tmp, start_cmd, start);
		tmp = tmp->next;
	}
}

int	ft_count_red(t_words **words, int start)
{
	int		res;
	t_words	*tmp;

	res = 0;
	tmp = *words;
	while (start--)
		tmp = tmp->next;
	while (tmp && !(tmp->word[0] == '|' && tmp->active))
	{
		if ((tmp->word[0] == '>' || tmp->word[0] == '<') && tmp->active)
		{
			res++;
			tmp = tmp->next;
			if (tmp && !(tmp->word[0] == '|' && tmp->active))
				res++;
		}
		else
			tmp = tmp->next;
	}
	return (res);
}

void	ft_change_double_red(t_cmd **cmd)
{
	int		i;
	t_cmd	*tmp;

	tmp = *cmd;
	i = 1;
	while (tmp)
	{
		if (ft_strcmp(tmp->cmd, "<<") == 0)
		{
			ft_create_new_file(tmp, i);
			i++;
		}
		else if (!ft_strncmp_nr(tmp->cmd, "echo", 4))
		{
			ft_echo_fill(tmp);
		}
		tmp = tmp->next;
	}
}
