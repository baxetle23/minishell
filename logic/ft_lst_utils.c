#include "../includes/minishell.h"

// char	*ft_strdup_part(const char *s1, int start, int len)
// {
// 	int		i;
// 	char	*s;

// 	i = start;
// 	s = malloc((len + 1) * sizeof(char));
// 	if (!s)
// 		return (0);
// 	while (i < len + start && s1[i] != '\0')
// 	{
// 		s[i - start] = s1[i];
// 		i++;
// 	}
// 	s[i - start] = '\0';
// 	return (s);
// }

// t_env	*ft_lstnew_env(char *s)
// {
// 	t_env	*new;
// 	int		pos;

// 	new = (t_env *)malloc(sizeof(t_env));
// 	if (!new)
// 		return (0);
// 	pos = 0;
// 	while (s[pos] != '=')
// 		pos++;
// 	new->key = ft_strdup_part(s, 0, pos);
// 	new->value = ft_strdup_part(s, pos + 1, ft_strlen(s));
// 	new->next = NULL;
// 	return (new);
// }

// void	ft_add_env(t_env **lst, t_env *new)
// {
// 	t_env	*buf;

// 	buf = *lst;
// 	if (!buf)
// 		*lst = new;
// 	else
// 	{
// 		while (buf->next != NULL)
// 			buf = buf->next;
// 		buf->next = new;
// 	}
// }

// void	ft_lstclear_env(t_env **env)
// {
// 	t_env	*tmp;
// 	t_env	*cur;

// 	tmp = *env;
// 	while (tmp)
// 	{
// 		cur = tmp;
// 		tmp = tmp->next;
// 		free(cur->key);
// 		free(cur->value);
// 		free(cur);
// 	}
// }

// char	*ft_env_search(char *find, t_env **env)
// {
// 	t_env	*buf;

// 	buf = *env;
// 	if (!buf)
// 	{
// 		free (find);
// 		return (ft_strdup(""));
// 	}
// 	while (buf)
// 	{
// 		if (!ft_strcmp(find, buf->key))
// 		{
// 			free(find);
// 			return (ft_strdup(buf->value));
// 		}
// 		buf = buf->next;
// 	}
// 	free(find);
// 	return (ft_strdup(""));
// }

// t_env	*ft_get_list_env(char *find, t_env **env)
// {
// 	t_env	*tmp;

// 	tmp = *env;
// 	while (tmp)
// 	{
// 		if (!ft_strcmp(find, tmp->key))
// 			return (tmp);
// 		tmp = tmp->next;
// 	}
// 	return (NULL);
// }

// int	ft_get_list_environments(char **e, t_env **env)
// {
// 	int		i;
// 	t_env	*new;

// 	i = -1;
// 	while (e[++i])
// 	{
// 		new = ft_lstnew_env(e[i]);
// 		if (!new)
// 		{
// 			ft_lstclear_env(env);
// 			return (0);
// 		}
// 		ft_add_env(env, new);
// 	}

// 	new = ft_get_list_env("OLDPWD", env);
// 	if (new)
// 		new->value = NULL;
// 	return (1);

// }
//---------------------------------------------

void print_comand_arg(t_cmd *cmd)
{
	int i = 0;
	printf(GREEN "name: %s\n" RESET, cmd->cmd);
	if (cmd->args)
	{
		printf(GREEN "arg: " RESET);
		while (cmd->args[i]) {
			printf(GREEN " %s" RESET, cmd->args[i]);
			i++;
		}
		printf("\n");
	}
		
}

void print_envp(t_env *envp)
{
	t_env *tmp = envp;
	printf(RED "__________PRINT ENVP_________\n" RESET);
	while (tmp)
	{
		if (tmp->value)
			printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

t_env *find_list_envp(const char * key, t_env *envp)
{
	t_env *tmp;
	tmp = envp;
	while (tmp)
	{
		if (!ft_strncmp(key, tmp->key, ft_strlen(key) && ft_strlen(key) == ft_strlen(tmp->key)))
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}