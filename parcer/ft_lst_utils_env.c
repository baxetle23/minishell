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
	if (pos == 0)
	{
		write (1, "!", 1);
		new->key = ft_strdup(s);
		new->value = NULL;
	}
	else
	{
		new->key = ft_strdup_part(s, 0, pos);
		new->value = ft_strdup_part(s, pos + 1, ft_strlen(s));
	}
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
