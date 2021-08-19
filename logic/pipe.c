#include "../includes/minishell.h"

t_cmd	*pipe_exist(t_cmd *cmd)
{
	while (cmd)
	{
		if (!ft_strcmp(cmd->cmd, "|"))
			return (cmd);
		cmd = cmd->next;
	}
	return (NULL);
}

int	count_pipe(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		if (!ft_strcmp(cmd->cmd, "|"))
			i++;
		cmd = cmd->next;
	}
	return (i);
}

void	term(pid_t *pids, int n, int g_fd[2][2])
{
	int	i;

	i = 0;
	close(g_fd[0][0]);
	close(g_fd[0][1]);
	close(g_fd[1][0]);
	close(g_fd[1][1]);
	while (i <= n)
		kill(pids[i++], SIGKILL);
	exit(1);
}

void	term1(pid_t *pids, int n, int g_fd[2][2])
{
	int	i;

	i = 0;
	close(g_fd[0][0]);
	close(g_fd[0][1]);
	close(g_fd[1][0]);
	close(g_fd[1][1]);
	while (i <= n)
		kill(pids[i++], SIGKILL);
}

t_cmd	*get_cmd(t_cmd *cmd, int pos)
{
	int	i;

	i = 1;
	while (i != pos)
	{
		if (!ft_strcmp(cmd->cmd, "|"))
			i++;
		cmd = cmd->next;
	}
	return (cmd);
}
