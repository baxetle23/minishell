#include "../includes/minishell.h"

void print_sort_envp(t_env *envp)
{
	t_env *tmp = envp;
	printf(RED "__________PRINT SORT ENVP_________\n" RESET);
	while (tmp)
	{
		if (tmp->value)
			printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
		else
			printf("declare -x %s\n", tmp->key);
		tmp = tmp->next;
	}
}

int compare_env_element(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while(s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return s1[i] - s2[i];
		i++;
	}
	return (s1[i] - s2[i]);
}

int	sort_env(t_env *env)
{
	t_env *start;
	t_env *tmp;
	char *tmp2;
	int flag;

	start = env;
	while (start->next)
	{
		flag = 0;
		tmp = start;
		while (tmp->next)
		{
			//printf("compare %s and %s\n", tmp->key, tmp->next->key);
			if (compare_env_element(tmp->key, tmp->next->key) > 0)
			{
				//printf("dvigaem\n");
				tmp2 = tmp->key;
				tmp->key = tmp->next->key;
				tmp->next->key = tmp2;

				tmp2 = tmp->value;
				tmp->value = tmp->next->value;
				tmp->next->value = tmp2;
				flag = 1;
			}
		tmp = tmp->next;
		}
		if (flag == 0)
			break ;
	}
	return (0);
}

int check_variable(char *name)
{
	int i;

	i = 0;
	while (name[i] && name[i] != '=')
	{
		if (i == 0 && !ft_isalpha(name[i]))
			return 1;
		if (i != 0 && !ft_isalpha(name[i]) && !ft_isdigit(name[i]) && name[i] != '_')
			return 1;
		i++;
	}
	return (0);
}

void get_key_value(char **key, char **value, char *variable)
{
	char *separator;
	separator = ft_strchr(variable, '=');

	if(separator)
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

void add_variable(char *variable, t_env* env) 
{
	t_env	*new;
	char	*key;
	char	*value;

	new = (t_env *)malloc(sizeof(t_env));
	if (check_variable(variable)) {
		printf("export: '%s': not a valid identifier\n", variable);
		return ;
	}
	get_key_value(&key, &value, variable);
	if (value && ft_find_list_env(key, &env))
	{
		new = ft_find_list_env(key, &env);
		free(new->value);
		new->value = value;
	}
	else
	{
		if (!ft_find_list_env(key, &env))
		{
			//переменной нет
			new->key = key;
			new->value = value;
			new->next = NULL;
			ft_add_env(&env, new);
		}
	}
}

int	comand_export(t_cmd *cmd, t_env *env)
{
	if (!cmd->args[0]) {
		// распечатать переменные
		sort_env(env);
		print_sort_envp(env);
		return (0);
	} else {
		int i = -1;
		while (cmd->args[++i])
			add_variable(cmd->args[i], env);
	}
}