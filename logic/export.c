#include "../includes/minishell.h"

int	check_variable(char *name)
{
	int	i;

	i = 0;
	while (name[i] && name[i] != '=')
	{
		if (i == 0 && !ft_isalpha(name[i]))
			return (1);
		if (i != 0 && !ft_isalpha(name[i])
			&& !ft_isdigit(name[i]) && name[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	get_key_value(char **key, char **value, char *variable)
{
	char	*separator;

	separator = ft_strchr(variable, '=');
	if (separator)
	{
		*separator = 0;
		*key = ft_strdup(variable);
		*value = ft_strdup(separator + 1);
	}
	else
	{
		*key = ft_strdup(variable);
		*value = NULL;
	}
}

void	ft_add_new_env(t_env *new, char *key, char *value,	t_env *env)
{
	new->key = key;
	new->value = value;
	new->next = NULL;
	ft_add_env(&env, new);
}

int	add_variable(char *variable, t_env *env)
{
	t_env	*new;
	char	*key;
	char	*value;

	new = (t_env *)malloc(sizeof(t_env));
	if (check_variable(variable))
	{
		ft_putstr_fd(variable, 2);
		ft_putendl_fd(": not a valid identifier", 2);
		free(new);
		return (1);
	}
	get_key_value(&key, &value, variable);
	if (value && ft_find_list_env(key, &env))
	{
		change_value(new, key, env, value);
	}
	else
	{
		if (!ft_find_list_env(key, &env))
			ft_add_new_env(new, key, value, env);
		else
			free_function(key, value, new);
	}
	return (0);
}

int	comand_export(t_cmd *cmd, t_env *env)
{
	int	fd;
	int	i;

	fd = find_file_des(cmd);
	if (fd < 0)
		return (1);
	if (!cmd->args[0])
	{
		sort_env(env);
		print_sort_envp(env, fd);
		return (0);
	}
	else
	{
		i = -1;
		while (cmd->args[++i])
		{
			if (add_variable(cmd->args[i], env))
				return (1);
		}
	}
	return (0);
}
