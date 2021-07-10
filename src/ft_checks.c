#include "../includes/minishell.h"

/*
char *ft_lineclear(char *line, t_env **env)
{
	return (line);
}
*/

char	*ft_dollar(int *i, char *line, t_env **env)
{
	int		j;
	char	*find;
	(void)	env;

	j = *i + 1;
	while ((ft_isalpha(line[j]) || ft_isdigit(line[j])) && line[j] != '\0')
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
		if (line[j] == '\'' || line[j] == '\"' || line[j] == ' ' || line[j] == '$')
		{
			res = ft_strdup_part(line, *i, j - *i);
			*i = j;
			return (res);
		}
		j++;
	}
	res = ft_strdup_part(line, *i, j - *i);
//	if (line[j] != '\0')
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
		//if (line[j] == '\'' && line[j + 1] == '\'')
		//	j++;
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

int	ft_checkline(char *line, t_env **env, t_cmd **cmd)
{
	int		i;
	t_words	*words;
	t_words	*tmp;
	char	*res_word;
	(void) cmd;

//	clear_line = ft_lineclear(line, env);
	i = 0;
	words = NULL;
	res_word = ft_strdup("");
	while (line[i] != '\0')
	{
		//printf("-%c-\n", line[i]);
		while (line[i] == ' ')
		i++;
		if (ft_isalpha(line[i]) || ft_isdigit(line[i]))
			res_word = ft_strjoin_m(res_word, ft_char(&i, line, env));
		if (line[i] == '\'')
			res_word = ft_strjoin_m(res_word, ft_upostr(&i, line));
		if (line[i] == '$')
			res_word = ft_strjoin_m(res_word, ft_dollar(&i, line, env));
/*		if (line[i] == '\"')
			ft_kavich(&(i + 1), line, env, cmd);
		if (line[i] == '$')
			ft_dollar(&(i + 1), line, env, cmd);
		if (line[i] == '|')
			ft_pipe_char(&(i + 1), line, env, cmd);
		if (line[i] == '<' || line[i] == '>')
			ft_redir(&(i + 1), line, env, cmd);
		
*/		
		if (line[i] == ' ' || line[i] == '\0')
		{
			ft_addword(res_word, &words);
			res_word = ft_strdup("");
			if (line[i] == '\0')
				break;
		}
	//	i++;
	}
	free(res_word);
	tmp = words;
	while (tmp)
	{
		printf("%s|\n", tmp->word);
		tmp = tmp->next;
	}

	free(line);
	ft_lstclear_words(&words);
	
	return (1);
//	printf("%s\n", clear_line);
}
