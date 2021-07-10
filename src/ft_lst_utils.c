#include "../includes/minishell.h"

t_env	*ft_lstnew_env(char *s)
{
	t_env	*new;
	int		pos;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (0);
	pos = 0;
	while (s[pos] != '=')
		pos++;
	new->key = ft_strdup_part(s, 0, pos);
	new->value = ft_strdup_part(s, pos + 1, ft_strlen(s));
	new->next = NULL;
	return (new);
}

void	ft_add_env(t_env **lst, t_env *new)
{
	t_env	*buf;

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

void	ft_lstclear_env(t_env **env)
{
	t_env	*tmp;
	t_env	*cur;

	tmp = *env;
	while (tmp)
	{
		cur = tmp;
		tmp = tmp->next;
		free(cur->key);
		free(cur->value);
		free(cur);
	}
}

char	*ft_env_search(char *find, t_env **env)
{
	t_env	*buf;

	buf = *env;
	if (!buf)
	{
		free (find);
		return (ft_strdup(""));
	}
	while (buf)
	{
		if (!ft_strcmp(find, buf->key))
		{
			free(find);
			return (ft_strdup(buf->value));
		}
		buf = buf->next;
	}
	free(find);
	return (ft_strdup(""));
}




t_words	*ft_lstnew_word(char *s)
{
	t_words	*new;

	new = (t_words *)malloc(sizeof(t_words));
	if (!new)
		return (0);
	new->word = s;
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

int	ft_addword(char *word, t_words **lst)
{
	t_words	*new;

	new = ft_lstnew_word(word);
	if (!new)
		return (0);
	ft_lstadd_word(lst, new);
	return (1);
}

void	ft_lstclear_words(t_words **env)
{
	t_words	*tmp;
	t_words	*cur;

	tmp = *env;
	while (tmp)
	{
		cur = tmp;
		tmp = tmp->next;
		free(cur->word);
		free(cur);
	}
}
