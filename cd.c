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
		//mistake
		printf("cd: %s: No such file or directory\n", cmd->arg[0]);
		char **buffer;
		buffer = (char **)malloc(sizeof(char *) * 1);
		buffer[0] = NULL;
		output_to_fd(buffer, cmd);
		return (1);
	}
	if (!((ft_get_list_env("OLDPWD", &envp))->value))
	{
		//first call cd

		if (count_arg_cd(cmd) == 1)
		{	
			getcwd(oldpath, 10000);
			tmp = ft_get_list_env("OLDPWD", &envp);
			tmp->value = ft_strdup(oldpath);
			if (!chdir(cmd->arg[0])) {
				tmp = ft_get_list_env("PWD", &envp);
				free(tmp->value);
				getcwd(oldpath, 10000);
				tmp->value = ft_strdup(oldpath);
			}
			else
				//comeback olDPWD!!!!
				printf("cd: %s: No such file or directory\n", cmd->arg[0]);
		}
		else
		{
			//write(1, "test\n", 5);
			t_env *tmp_home = ft_get_list_env("HOME", &envp);
			getcwd(oldpath, 10000);
			tmp = ft_get_list_env("OLDPWD", &envp);
			tmp->value = ft_strdup(oldpath);
			tmp = ft_get_list_env("PWD", &envp);
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
			tmp = ft_get_list_env("OLDPWD", &envp);
			free (tmp->value);
			tmp->value = ft_strdup(oldpath);
			if (!chdir(cmd->arg[0])) {
				tmp = ft_get_list_env("PWD", &envp);
				free(tmp->value);
				getcwd(oldpath, 10000);
				tmp->value = ft_strdup(oldpath);
			}
			else
				printf("cd: %s: No such file or directory\n", cmd->arg[0]);
		}
		else
		{
			write(1, "test\n", 5);
			//go to home directoria
			t_env *tmp_home = ft_get_list_env("HOME", &envp);
			getcwd(oldpath, 10000);
			tmp = ft_get_list_env("OLDPWD", &envp);
			free (tmp->value);
			tmp->value = ft_strdup(oldpath);
			tmp = ft_get_list_env("PWD", &envp);
			free(tmp->value);
			tmp->value = ft_strdup(tmp_home->value);
		}
	}

	char **buffer;
	buffer = (char **)malloc(sizeof(char *) * 1);
	buffer[0] = NULL;
	output_to_fd(buffer, cmd);
	return (0);
}