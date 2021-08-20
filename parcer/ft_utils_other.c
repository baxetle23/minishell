#include "../includes/minishell.h"

int	ft_is_redirect(t_words *tmp)
{
	return ((tmp->word[0] == '<' || tmp->word[0] == '>') && tmp->active);
}

int	ft_is_pipe(t_words *tmp)
{
	return (tmp->word[0] == '|' && tmp->active);
}

int	ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

char	*ft_dollar_others(char *line, int *i, int j)
{
	if (line[j] == '$')
	{
		*i = j + 1;
		return (ft_itoa(getpid()));
	}
	else if (line[j] == '?')
	{
		*i = j + 1;
		return (ft_itoa(g_status_error));
	}
	else if (line[j] == '\0' || ft_is_space(line[j]))
	{
		*i = *i + 1;
		return (ft_strdup("$"));
	}
	return (NULL);
}
