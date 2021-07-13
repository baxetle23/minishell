#include "../includes/minishell.h"

int	ft_lst_words_length(t_words **words)
{
	t_words	*tmp;
	int		i;

	if (!words)
		return (0);
	i = 0;
	tmp = *words;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_words	*ft_lstnew_word(char *s, int active)
{
	t_words	*new;

	new = (t_words *)malloc(sizeof(t_words));
	if (!new)
		return (0);
	new->word = s;
	new->active = active;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_word(t_words **lst, t_words *new)
{
	t_words	*buf;

	buf = *lst;
	if (!buf)
		*lst = new;
	else
	{
		while (buf->next != NULL)
			buf = buf->next;
		buf->next = new;
	}
}

int	ft_addword(char *word, t_words **lst, int active)
{
	t_words	*new;

	new = ft_lstnew_word(word, active);
	if (!new)
		return (0);
	ft_lstadd_word(lst, new);
	return (1);
}

int	ft_check_last_word(char *check, t_words **words)
{
	t_words	*tmp;

	tmp = *words;
	if (tmp)
		return (1);
	while (tmp->next)
		tmp = tmp->next;
	return (ft_strcmp(check, tmp->word));
}

