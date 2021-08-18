#include "../includes/minishell.h"

int	count_arg_cd(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
		i++;
	if (i >= 2)
		return (-1);
	if (i == 1)
		return (1);
	return (0);
}

int	call_cd_go_home(t_env *envp, char *oldpath, t_env *tmp)
{
	t_env	*tmp_home;

	tmp_home = ft_find_list_env("HOME", &envp);
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
	return (0);
}

int	call_cd(t_cmd *cmd, t_env *envp, char *oldpath)
{
	t_env	*tmp;
	int		status;

	status = 0;
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
		status = call_cd_go_home(envp, oldpath, tmp);
	else
	{
		ft_putstr_fd(cmd->args[0], 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (1);
	}
	return (status);
}

int	first_call_cd(t_cmd *cmd, t_env *envp, char *oldpath)
{
	t_env	*tmp;
	int		status;

	status = 0;
	getcwd(oldpath, 10000);
	tmp = ft_find_list_env("OLDPWD", &envp);
	tmp->value = ft_strdup(oldpath);
	if (!chdir(cmd->args[0]))
	{
		tmp = ft_find_list_env("PWD", &envp);
		free(tmp->value);
		getcwd(oldpath, 10000);
		tmp->value = ft_strdup(oldpath);
	}
	else if (!ft_strcmp(cmd->args[0], "~"))
		status = call_cd_go_home(envp, oldpath, tmp);
	else
	{
		ft_putstr_fd(cmd->args[0], 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (1);
	}
	return (status);
}

int	comand_cd(t_cmd *cmd, t_env *envp)
{
	t_env	*tmp;
	char	oldpath[10000];

	if (count_arg_cd(cmd) != 1)
	{
		ft_putendl_fd("cd with only a relative or absolute path", 2);
		return (1);
	}
	if (!((ft_find_list_env("OLDPWD", &envp))->value))
		return (first_call_cd(cmd, envp, oldpath));
	else
		return (call_cd(cmd, envp, oldpath));
}
