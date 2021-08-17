#include "../includes/minishell.h"

int	count_arg_cd(t_cmd *cmd)
{
	int i;

	i = 0;

	while (cmd->args[i])
		i++;
	if (i >= 2)
		return -1;
	if (i == 1)
		return 1;
	return (0);
}

int	comand_cd(t_cmd *cmd, t_env *envp)
{
	t_env	*tmp;
	char	oldpath[10000];

	if (count_arg_cd(cmd) == 0 || count_arg_cd(cmd) != 1)
	{
		//mistake
		ft_putendl_fd("cd with only a relative or absolute path", 2);
		return (1);
	}
	if (!((ft_find_list_env("OLDPWD", &envp))->value))
	{
		//first call cd
		if (count_arg_cd(cmd) == 1)
		{	
			getcwd(oldpath, 10000);
			tmp = ft_find_list_env("OLDPWD", &envp);
			tmp->value = ft_strdup(oldpath);
			if (!chdir(cmd->args[0])) {
				tmp = ft_find_list_env("PWD", &envp);
				free(tmp->value);
				getcwd(oldpath, 10000);
				tmp->value = ft_strdup(oldpath);
			}
			else if (!ft_strcmp(cmd->args[0], "~"))
			{
				//go home!!! function
				t_env *tmp_home = ft_find_list_env("HOME", &envp);
				if (tmp_home == NULL)
				{
					ft_putendl_fd("cd: HOME not set", 2);
					return (1);
				}
				getcwd(oldpath, 10000);
				tmp = ft_find_list_env("OLDPWD", &envp);
				free (tmp->value);
				tmp->value = ft_strdup(oldpath);
				tmp = ft_find_list_env("PWD", &envp);
				free(tmp->value);
				tmp->value = ft_strdup(tmp_home->value);
			}
			else
			{
				//comeback olDPWD!!!!
				ft_putstr_fd(cmd->args[0], 2);
				ft_putendl_fd(": No such file or directory", 2);
				return (1);
			}
		}
		else
		{
			t_env *tmp_home = ft_find_list_env("HOME", &envp);
			if (tmp_home == NULL)
			{
				ft_putendl_fd("cd: HOME not set", 2);
				return (1);
			}
			getcwd(oldpath, 10000);
			tmp = ft_find_list_env("OLDPWD", &envp);
			tmp->value = ft_strdup(oldpath);
			tmp = ft_find_list_env("PWD", &envp);
			free(tmp->value);
			tmp->value = ft_strdup(tmp_home->value);
		}
	}
	else
	{
		//OLDPWD not NULL
		if (count_arg_cd(cmd) == 1)
		{
			//have argument
			getcwd(oldpath, 10000);
			tmp = ft_find_list_env("OLDPWD", &envp);
			free (tmp->value);
			tmp->value = ft_strdup(oldpath);
			if (!chdir(cmd->args[0]))
			{
				tmp = ft_find_list_env("PWD", &envp);
				free(tmp->value);
				getcwd(oldpath, 10000);
				tmp->value = ft_strdup(oldpath);
			}
			else if (!ft_strcmp(cmd->args[0], "~"))
			{
				//go home!!! function
				t_env *tmp_home = ft_find_list_env("HOME", &envp);
				if (tmp_home == NULL)
				{
					ft_putendl_fd("cd: HOME not set", 2);
					return (1);
				}
				getcwd(oldpath, 10000);
				tmp = ft_find_list_env("OLDPWD", &envp);
				free (tmp->value);
				tmp->value = ft_strdup(oldpath);
				tmp = ft_find_list_env("PWD", &envp);
				free(tmp->value);
				tmp->value = ft_strdup(tmp_home->value);
			}
			else
			{
				ft_putstr_fd(cmd->args[0], 2);
				ft_putendl_fd(": No such file or directory", 2);
				return (1);
			}
		}
		else
		{
			//go to home directoria
			t_env *tmp_home = ft_find_list_env("HOME", &envp);
			if (tmp_home == NULL)
			{
				ft_putendl_fd("cd: HOME not set", 2);
				return (1);
			}
			getcwd(oldpath, 10000);
			tmp = ft_find_list_env("OLDPWD", &envp);
			free (tmp->value);
			tmp->value = ft_strdup(oldpath);
			tmp = ft_find_list_env("PWD", &envp);
			free(tmp->value);
			tmp->value = ft_strdup(tmp_home->value);
		}
	}
	return (0);
}