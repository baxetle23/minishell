#include "../includes/minishell.h"

int	ft_is_redirect(t_words *tmp)
{
	return ((tmp->word[0] == '<' || tmp->word[0] == '>') && tmp->active);
}

int ft_is_pipe(t_words *tmp)
{
	return (tmp->word[0] == '|' && tmp->active);
}
