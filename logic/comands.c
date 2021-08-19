#include "../includes/minishell.h"

int	comand_exit(t_cmd *cmd)
{
	int	fd;

	fd = find_file_des(cmd);
	if (fd < 0)
	{
		ft_putendl_fd("error open file", 2);
		return (1);
	}
	ft_putendl_fd("exit", 1);
	if (cmd->args && cmd->args[0])
	{
		fd = ft_atoi(cmd->args[0]);
		if (fd > 255)
			exit(WEXITSTATUS(fd) - 1);
		else
			exit(fd);
	}
	else
		exit(g_status_error);
}

void	init_for_pipe(int *i, pid_t **pids, int *save, int argc)
{
	*i = 0;
	*pids = malloc(sizeof(pid_t) * argc);
	*save = dup(STDIN_FILENO);
}

void	plus_SHLVL(char **o_env)
{
	int	i;
	int	j;
	int	number;

	i = -1;
	j = -1;
	while (o_env[++i])
	{
		if (!ft_strncmp(o_env[i], "SHLVL", 5))
		{
			while (o_env[i][++j])
				if (o_env[i][j] == '=')
					break ;
			break ;
		}
	}
	number = ft_atoi(&(o_env[i][j + 1])) + 1;
	o_env[i] = ft_strjoin("SHLVL=", ft_itoa(number));
}

void	check_minishell(char *name, char **o_env, t_cmd *cmd)
{
	int	last_sl;
	int	i;

	(void)cmd;
	i = -1;
	while (name[++i])
		if (name[i] == '/')
			last_sl = i;
	if (!ft_strncmp(name + last_sl + 1, "minishell", 9))
		plus_SHLVL(o_env);
}
