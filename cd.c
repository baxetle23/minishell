#include "includes/minishell.h"

//обработать поведение эрно

int	count_arg_cd(t_cmd *cmd)
{
	int i;

	i = 0;
	while (cmd->arg[i])
		i++;
	if (i >= 2)
		return -1;
	if (i == 1)
		return 1;
	return (0);
}

int	comand_cd(t_cmd *cmd, t_env *envp)
{
	t_env *tmp;
	char oldpath[10000];


	if (count_arg_cd(cmd) && count_arg_cd(cmd) != 1)
	{
		//произошла ошибка
		printf("cd: %s: No such file or directory\n", cmd->arg[0]);
		return (1);
	}
	if (!find_list_envp("OLDPWD", envp))
	{
		//первый вызов cd
		if (count_arg_cd(cmd) == 1)
		{
			getcwd(oldpath, 10000);
			tmp = find_list_envp("OLDPWD", envp);
			tmp->value = ft_strdup(oldpath);
			if (!chdir(cmd->arg[0])) {
				tmp = find_list_envp("PWD", envp);
				free(tmp->value);
				getcwd(oldpath, 10000);
				tmp->value = ft_strdup(oldpath);
			}
			else
				//вернуть значение OLDPWD!!!!!!!!!
				printf("cd: %s: No such file or directory\n", cmd->arg[0]);
		}
		else
		{
			t_env *tmp_home = find_list_envp("HOME", envp);
			getcwd(oldpath, 10000);
			tmp = find_list_envp("OLDPWD", envp);
			tmp->value = ft_strdup(oldpath);
			tmp = find_list_envp("PWD", envp);
			free(tmp->value);
			tmp->value = ft_strdup(tmp_home->value);
			print_envp(envp);
		}
	}
	else
	{
		//есть OLDPWD
		if (count_arg_cd(cmd) == 1)
		{
			//указан путь
			getcwd(oldpath, 10000);
			tmp = find_list_envp("OLDPWD", envp);
			free (tmp->value);
			tmp->value = ft_strdup(oldpath);
			if (!chdir(cmd->arg[0])) {
				tmp = find_list_envp("PWD", envp);
				free(tmp->value);
				getcwd(oldpath, 10000);
				tmp->value = ft_strdup(oldpath);
			}
			else
				printf("cd: %s: No such file or directory\n", cmd->arg[0]);
		}
		else
		{
			//home directoria
			t_env *tmp_home = find_list_envp("HOME", envp);
			getcwd(oldpath, 10000);
			tmp = find_list_envp("OLDPWD", envp);
			free (tmp->value);
			tmp->value = ft_strdup(oldpath);
			tmp = find_list_envp("PWD", envp);
			free(tmp->value);
			tmp->value = ft_strdup(tmp_home->value);
		}
		print_envp(envp);
	}
	return (0);
}