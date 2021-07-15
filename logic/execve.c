#include "../includes/minishell.h"

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

char	*get_addres(char **envp, char *cmd_string)
{
	t_pipex	a;

	a.i = 0;
	while (ft_strncmp(envp[a.i], "PATH=", 5))
		a.i++;
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
	exit (5);
}

void call_execve_process(t_cmd *cmd, char **o_env)
{
	int fd;
	char *name_programm;

	fd = find_file_des(cmd);
	if (fd < 0)
		exit (1);
	dup2(fd, STDOUT_FILENO);
	name_programm = get_addres(o_env, cmd->cmd);
	execve(name_programm, cmd->flags, o_env);
	exit (1);
}

int	comand_exve(t_cmd *cmd, char **o_env)
{
	int pid;
	pid = fork();
	if (pid < 0)
		exit (1);
	if (pid == 0)
	{
		call_execve_process(cmd, o_env);
	}
	wait(NULL);
	return (0);
}