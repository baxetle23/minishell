#include "../includes/minishell.h"

char	*ft_redir(int *i, char *line, t_words **words)
{
	char	first;
	int		j;

	first = line[*i];
	j = *i + 1;
	if (line[*i + 1] == first)
	{
		ft_addword(ft_strdup_part(line, *i, 2), words, 1);
		*i = *i + 2;
	}
	else
	{
		ft_addword(ft_strdup_part(line, *i, 1), words, 1);
		*i = *i + 1;
	}
	ft_switch_spaces(i, line);
	return (0);
}

void	ft_checkline_1(char **res_word, char *line, t_words **words, int *i)
{
	if (line[*i] == '\'')
		*res_word = ft_strjoin_m(*res_word, ft_upostr(i, line));
	if (line[*i] == '|')
	{
		if (i != 0 && !ft_spec_char(line[*i - 1]))
		{
			ft_addword(*res_word, words, 0);
			*res_word = NULL;
		}
		ft_pipe(i, line, words);
		ft_switch_spaces(i, line);
	}
	if (line[*i] == '<' || line[*i] == '>')
	{
		if (i != 0 && !ft_spec_char(line[*i - 1]))
		{
			ft_addword(*res_word, words, 0);
			*res_word = NULL;
		}
		ft_redir(i, line, words);
	}
}

void	ft_checkline_2(char **res_word, char *line, t_env **env, int *i)
{
	if (!ft_is_space(line[*i]) && line[*i] != '\'' && line[*i] != '$'
		&& !ft_spec_char(line[*i]))
		*res_word = ft_strjoin_m(*res_word, ft_char(i, line, env));
	if (line[*i] == '$')
		*res_word = ft_strjoin_m(*res_word, ft_dollar(i, line, env));
	if (line[*i] == '\"')
		*res_word = ft_strjoin_m(*res_word, ft_kavichki(i, line, env));
}

void	ft_checkline_3(char **res_word, char *line, t_words **words, int *i)
{
	if (line[*i] == ' ' || line[*i] == '\0')
	{
		if (!(line[*i] == '\0' && *i > 0 && ft_spec_char(line[*i - 1])))
		{
			ft_addword(*res_word, words, 0);
			*res_word = NULL;
		}
	}
}

int	ft_checkline(char *line, t_env **env, t_cmd **cmd, char **envir)
{
	int		i;
	t_words	*words;
	char	*res_word;

	i = 0;
	words = NULL;
	res_word = NULL;
	while (line[i] != '\0')
	{
		ft_switch_spaces(&i, line);
		ft_checkline_2(&res_word, line, env, &i);
		ft_checkline_1(&res_word, line, &words, &i);
		ft_checkline_3(&res_word, line, &words, &i);
	}
	if (words == NULL)
	{
		free(line);
		return (0);
	}
	ft_get_comm(&words, cmd, 0, 0);
	if (ft_comm_check(cmd))
		mainalex(cmd, env, envir);
	ft_clear_all(&words, cmd, line, res_word);
	return (1);
}
