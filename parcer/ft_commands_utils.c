#include "../includes/minishell.h"

char	*ft_get_cmd_by_start(t_words **words, int start)
{
	t_words	*tmp;

	tmp = *words;
	while (start--)
		tmp = tmp->next;
	return (ft_strdup(tmp->word));
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
