#include "../includes/minishell.h"

void	ft_switch_spaces(int *i, char *line)
{
	while (line[*i] == ' ')
		*i = *i + 1;
}

void	ft_pipe(int *i, char *line, t_words **words)
{
	int		j;
	(void)line;

	j = *i + 1;
	*i = j;
	ft_addword(ft_strdup("|"), words, 1);
}
