#include "../includes/minishell.h"

char	*ft_get_cmd_by_start(t_words **words, int start)
{
	t_words	*tmp;

	tmp = *words;
	while (start--)
		tmp = tmp->next;
	return (ft_strdup(tmp->word));
}

void	ft_add_all_redirects(t_words **words, int start, t_cmd **start_cmd)
{
	t_words	*tmp;
	char	**args;
	t_cmd	*cmd;


	tmp = *words;

	while (start--)
		tmp = tmp->next;
	
	while (tmp && !(tmp->word[0] == '|' && tmp->active))
	{
		if ((tmp->word[0] == '>' || tmp->word[0] == '<') && tmp->active)
		{
			if (tmp->next && !(tmp->next->active))
			{
				args = (char **)malloc(sizeof(char **) * 2);
				args[0] = ft_strdup(tmp->next->word);
				args[1] = NULL;
				cmd = ft_lstnew_cmd(ft_strdup(tmp->word), get_empty_m(), args);
				start = start + 1;
				tmp = tmp->next;
			}
			else
				cmd = ft_lstnew_cmd(ft_strdup(tmp->word), get_empty_m(), get_empty_m());
			ft_lstadd_cmd(start_cmd, cmd);
		}
		tmp = tmp->next;
	}
}

int	ft_simbols_in_word(char *word)
{
	if (ft_strchr(word, '<') || ft_strchr(word, '>') || ft_strchr(word, '|'))
		return (1);
	return (0);
}

int	ft_check_acitve(t_words **words, int start)
{
	t_words	*tmp;

	tmp = *words;
	while (start--)
		tmp = tmp->next;
	return (tmp->active);
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
