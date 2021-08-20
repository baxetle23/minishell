#include "../includes/minishell.h"

void	ft_pipe(int *i, char *line, t_words **words)
{
	int		j;

	(void)line;
	j = *i + 1;
	*i = j;
	ft_addword(ft_strdup("|"), words, 1);
}

char	*ft_dollar(int *i, char *line, t_env **env)
{
	int		j;
	char	*find;

	j = *i + 1;
	if (line[j] == '$' || line[j] == '?'
		|| (line[j] == '\0' || ft_is_space(line[j])))
		return (ft_dollar_others(line, i, j));
	while ((ft_isalpha(line[j]) || ft_isdigit(line[j]) || line[j] == '_')
		&& line[j] != '\0')
		j++;
	find = ft_strdup_part(line, *i + 1, j - *i - 1);
	if (line[*i] != '\0')
		*i = j;
	else
		*i = j + 1;
	return (ft_env_search(find, env));
}

char	*ft_char(int *i, char *line, t_env **env)
{
	int		j;
	char	*res;

	(void) env;
	j = *i;
	res = NULL;
	while (line[j] != '\0')
	{
		if (line[j] == '\'' || line[j] == '\"' || line[j] == ' '
			|| line[j] == '$' || line[j] == '|' || line[j] == '<'
			|| line[j] == '>')
		{
			res = ft_strdup_part(line, *i, j - *i);
			*i = j;
			return (res);
		}
		j++;
	}
	res = ft_strdup_part(line, *i, j - *i);
	*i = j;
	return (res);
}

char	*ft_upostr(int *i, char *line)
{
	int		j;
	char	*res;

	j = *i + 1;
	while (line[j] != '\0')
	{
		if (line[j] == '\'')
		{
			res = ft_strdup_part(line, *i + 1, j - *i - 1);
			*i = j + 1;
			return (res);
		}
		j++;
	}
	*i = j;
	return (ft_strdup(""));
}

char	*ft_kavichki(int *i, char *line, t_env **env)
{
	int		j;
	char	*res;

	j = *i + 1;
	res = ft_strdup("");
	while (line[j] != '\0')
	{
		if (line[j] == '$')
		{
			res = ft_strjoin_m(res, ft_strdup_part(line, *i + 1, j - *i - 1));
			res = ft_strjoin_m(res, ft_dollar(&j, line, env));
			*i = j - 1;
		}
		if (line[j] == '\"')
		{
			res = ft_strjoin_m(res, ft_strdup_part(line, *i + 1, j - *i - 1));
			*i = j + 1;
			return (res);
		}
		j++;
	}
	*i = j;
	return (res);
}
