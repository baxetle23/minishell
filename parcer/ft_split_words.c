#include "../includes/minishell.h"

char	*ft_dollar(int *i, char *line, t_env **env)
{
	int		j;
	char	*find;

	j = *i + 1;
	if (line[j] == '$')
	{
		*i = j + 1;
		return(ft_strdup(ft_itoa(getpid())));
	}
	j = *i + 1;
	if (line[j] == '?')
	{
		*i = j + 1;
		printf("errno = %d, name = %s", errno, strerror(errno));
		return(ft_strdup(ft_itoa(errno)));
	}
	while ((ft_isalpha(line[j]) || ft_isdigit(line[j]) || line[j] == '_') && line[j] != '\0')
		j++;
	find = ft_strdup_part(line, *i + 1, j - *i - 1);
	if(line[*i] != '\0')
		*i = j;
	else
		*i = j + 1;
	return (ft_env_search(find, env));
}

char	*ft_char(int *i, char *line, t_env **env)
{
	int		j;
	char	*res;
	(void)	env;

	j = *i;
	res = NULL;
	while (line[j] != '\0')
	{
		if (line[j] == '\'' || line[j] == '\"' || line[j] == ' ' || line[j] == '$' || line[j] == '|' || line[j] == '<' || line[j] == '>')
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
	while ( line[j] != '\0')
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
	(void)	env;

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

char	*ft_redir(int *i, char *line, t_words **words)
{
	(void)	words;
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
//	*res_word = ft_strdup("");
	ft_switch_spaces(i, line);
	return (0);
}

int	ft_checkline(char *line, t_env **env, t_cmd **cmd)
{
	int		i;
	t_words	*words;
	t_words	*tmp;
	char	*res_word;
//	(void) cmd;

	i = 0;
	words = NULL;
	res_word = ft_strdup("");
	while (line[i] != '\0')
	{
//		printf("|%c|\n", line[i]);
		ft_switch_spaces(&i, line);
		if (ft_isprint(line[i]) && line[i] != '\'' && line[i] != '$' && line[i] != '|' && line[i] != '<' && line[i] != '>')
			res_word = ft_strjoin_m(res_word, ft_char(&i, line, env));
		if (line[i] == '\'')
			res_word = ft_strjoin_m(res_word, ft_upostr(&i, line));
		if (line[i] == '$')
			res_word = ft_strjoin_m(res_word, ft_dollar(&i, line, env));
		if (line[i] == '|')
		{
			if (i != 0 && (line[i - 1] != ' ' && line[i - 1] != '>' && line[i - 1] != '<' && line[i - 1] != '|'))
			{
				ft_addword(res_word, &words, 0);
				res_word = ft_strdup("");
			}
			ft_pipe(&i, line, &words);
			ft_switch_spaces(&i, line);
		}
		if (line[i] == '\"')
			res_word = ft_strjoin_m(res_word, ft_kavichki(&i, line, env));
		if (line[i] == '<' || line[i] == '>')
		{
			if (i != 0 && (line[i - 1] != ' ' && line[i - 1] != '>' && line[i - 1] != '<' && line[i - 1] != '|'))
			{
				ft_addword(res_word, &words, 0);
				res_word = ft_strdup("");
			}
			ft_redir(&i, line, &words);
		}
		if (line[i] == ' ' || line[i] == '\0')// || line[i] == '|')
		{
			if (!(line[i] == '\0' && i > 0 && (line[i - 1] == ' ' || line[i - 1] == '|' || line[i - 1] == '>' || line[i - 1] == '<')))
			{
				ft_addword(res_word, &words, 0);
				res_word = ft_strdup("");
			}
		}
	}
	free(res_word);
	tmp = words;

//	ft_fill_activity(&words, line);
//	ft_print_lst_words(&words);

//	t_cmd *cmd;

//	cmd = NULL;
	ft_get_commands(&words, line, cmd);

	
	ft_print_lst_cmds(cmd);
	

	mainalex(cmd, env);
	
	free(line);
	ft_lstclear_words(&words);
	ft_lstclear_cmds(cmd);
	return (1);
}
