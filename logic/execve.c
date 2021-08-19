#include "../includes/minishell.h"

char	**get_flags(t_cmd *cmd)
{
	int		i;
	int		j;
	char	**flags;

	i = 0;
	j = 0;
	while (cmd->flags[i])
		i++;
	while (cmd->args[j++])
		i++;
	flags = (char **)malloc(sizeof(char *) * (i + 1));
	flags[i] = NULL;
	i = 0;
	j = 0;
	while (cmd->flags[i])
	{
		flags[i] = ft_strdup(cmd->flags[i]);
		i++;
	}
	while (cmd->args[j])
		flags[i++] = ft_strdup(cmd->args[j++]);
	return (flags);
}

int	absolute_path(char *name_programm)
{
	int	i;

	i = 0;
	while (name_programm[i])
	{
		if (name_programm[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	*exit_with_print(t_pipex *a, int flag)
{
	ft_putstr_fd(a->comand[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	if (flag)
		free_memory(a->strings_way, a->comand);
	exit (127);
}

char	*get_addres(char **envp, t_env *my_envp, char *cmd_string)
{
	t_pipex	a;
	t_env	*path;

	a.i = 0;
	path = ft_find_list_env("PWD", &my_envp);
	while (ft_strncmp(envp[a.i], "PATH=", 5))
		if (a.i++ == 1000)
			exit_with_print(&a, 0);
	a.strings_way = ft_split(envp[a.i] + 5, ':');
	a.comand = ft_split(cmd_string, ' ');
	a.i = 0;
	while (a.strings_way[a.i])
	{
		a.addres = ft_strjoin(a.strings_way[a.i], "/");
		a.addres_full = ft_strjoin(a.addres, a.comand[0]);
		free(a.addres);
		if (access(a.addres_full, F_OK) == 0)
		{
			free_memory(a.strings_way, a.comand);
			return (a.addres_full);
		}
		free(a.addres_full);
		a.i++;
	}
	return (exit_with_print(&a, 1));
}

void	call_execve_process(t_cmd *cmd, t_env *envp, char **o_env)
{
	int		fd;
	char	*name_programm;
	char	**flags;

	fd = find_file_des(cmd);
	if (fd < 0)
		exit (1);
	dup2(fd, STDOUT_FILENO);
	if (absolute_path(cmd->cmd))
		name_programm = ft_strdup(cmd->cmd);
	else
		name_programm = get_addres(o_env, envp, cmd->cmd);
	flags = get_flags(cmd);
	check_minishell(name_programm, o_env, cmd);
	execve(name_programm, flags, o_env);
	exit (1);
}
