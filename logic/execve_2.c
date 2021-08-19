#include "../includes/minishell.h"

int	check_key_value(t_env **envp)
{
	if (!ft_strncmp((*envp)->key, "PATH", 4))
	{
		if ((*envp)->value != NULL)
			return (0);
		else
		{
			return (1);
		}
	}
	else
	{
		(*envp) = (*envp)->next;
	}
	if (*envp == NULL)
		return (1);
	return (0);
}

int	free_normi(t_pipex *a)
{
	free_memory(a->strings_way, a->comand);
	free(a->addres_full);
	return (1);
}

int	check_addres(t_env *my_envp, char *cmd_string)
{
	t_pipex	a;
	t_env	*path;

	path = ft_find_list_env("PWD", &my_envp);
	while (ft_strncmp(my_envp->key, "PATH", 4))
		if (check_key_value(&my_envp))
			return (0);
	if (my_envp->value == NULL)
		return (0);
	a.strings_way = ft_split(my_envp->value, ':');
	a.comand = ft_split(cmd_string, ' ');
	a.i = 0;
	while (a.strings_way[a.i])
	{
		a.addres = ft_strjoin(a.strings_way[a.i++], "/");
		a.addres_full = ft_strjoin(a.addres, a.comand[0]);
		free(a.addres);
		if (access(a.addres_full, F_OK) == 0)
			return (free_normi(&a));
		free(a.addres_full);
	}
	free_memory(a.strings_way, a.comand);
	return (0);
}

int	check_path(t_cmd *cmd, t_env *envp)
{
	t_env	*tmp;

	tmp = envp;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, "PATH", 4)
			&& check_addres(envp, cmd->cmd))
			return (0);
		tmp = tmp->next;
	}
	ft_putstr_fd(cmd->cmd, 2);
	ft_putendl_fd(": No such file or directory", 2);
	g_status_error = 127;
	return (1);
}

int	comand_exve(t_cmd *cmd, t_env *envp, char **o_env)
{
	int	pid;

	if (!absolute_path(cmd->cmd) && check_path(cmd, envp))
		return (g_status_error);
	pid = fork();
	if (pid < 0)
		exit (1);
	if (pid == 0)
	{
		call_execve_process(cmd, envp, o_env);
	}
	wait(&g_status_error);
	g_status_error = WEXITSTATUS(g_status_error);
	return (g_status_error);
}
