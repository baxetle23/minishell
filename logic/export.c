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


int	comand_export(t_cmd *cmd, t_env *env)
{
	(void)cmd;
	sort_env(env);
	print_sort_envp(env);
	return (0);
}