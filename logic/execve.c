#include "../includes/minishell.h"

char	**get_flags(t_cmd *cmd)
{
	int	i;
	int	j;
	char **flags;

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
	while(cmd->flags[i])
	{
		flags[i] = ft_strdup(cmd->flags[i]);
		i++;
	}
	while(cmd->args[j])
	{
		flags[i] = ft_strdup(cmd->args[j]);
		i++;
		j++;
	}
	return (flags);
}

int	absolute_path(char *name_programm)
{
	int i;

	i = 0;
	while(name_programm[i])
	{
		if (name_programm[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

void	free_memory(char **split1, char **split2)
{
	int	i;

	i = 0;
	while (split1[i])
		free(split1[i++]);
	i = 0;
	while (split2[i])
		free(split2[i++]);
	free(split2);
	free(split1);
}

char	*get_addres(char **envp, t_env *my_envp, char *cmd_string)
{
	t_pipex	a;

	a.i = 0;
	t_env *path = ft_find_list_env("PWD", &my_envp);
	while (ft_strncmp(envp[a.i], "PATH=", 5))
	{
		a.i++;
		if (a.i == 1000) {
			ft_putstr_fd(a.comand[0], 2);
			ft_putstr_fd(": command not found\n", 2);
			status_erorr = 127;
			exit (5);
		}
	}
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
	ft_putstr_fd(a.comand[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free_memory(a.strings_way, a.comand);
	status_erorr = 127;
	exit (5);
}

void change_envp(t_env *envp, char **o_env)
{
	int		i;
	char	*tmp;
	t_env	*path;

	i = 0;
	path = ft_find_list_env("PWD", &envp);
	while (o_env[i])
	{
		if (!ft_strncmp(o_env[i], "PWD=", 4))
			break ;
		i++;
	}
	tmp = ft_strjoin(path->key, "=");
	o_env[i] = ft_strjoin(tmp, path->value);
	ft_putendl_fd(o_env[i], 1);
}

void call_execve_process(t_cmd *cmd, t_env *envp, char **o_env)
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
	//change_envp(envp, o_env);
	execve(name_programm, flags, o_env);
	status_erorr = 127;
	exit (1);
}

int	comand_exve(t_cmd *cmd, t_env* envp, char **o_env)
{
	int pid;
	pid = fork();
	if (pid < 0)
		exit (1);
	if (pid == 0)
		call_execve_process(cmd, envp, o_env);
	wait(&status_erorr);
	return (0);
}