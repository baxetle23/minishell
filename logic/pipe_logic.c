#include "../includes/minishell.h"

void	close_fd(int g_fd[2][2])
{
	close(g_fd[0][0]);
	close(g_fd[0][1]);
	close(g_fd[1][0]);
	close(g_fd[1][1]);
}

void	logic_pipe_execute(pid_t *pids, int g_fd[2][2], int i, int argc)
{
	close(g_fd[i & 1][1]);
	close(g_fd[1 - (i & 1)][0]);
	if (i > 1 && dup2(g_fd[i & 1][0], 0) == -1)
		exit(1);
	close(g_fd[i & 1][0]);
	if (i != argc - 1)
	{
		if (dup2(g_fd[1 - (i & 1)][1], 1) == -1)
			exit(1);
	}
	close(g_fd[1 - (i & 1)][1]);
}

void	ebuchay_norma_sorry(int g_fd[2][2], int i, int argc, pid_t	*pids)
{
	close(g_fd[i & 1][0]);
	close(g_fd[i & 1][1]);
	wait(&g_status_error);
	if (g_status_error > 127)
		g_status_error = 256 - WEXITSTATUS(g_status_error);
	else
		g_status_error = WEXITSTATUS(g_status_error);
	if (i == argc - 1)
		close_fd(g_fd);
	if (pipe(g_fd[i & 1]) == -1)
		term1(pids, i, g_fd);
}

int	logic_pipe(t_cmd *cmd, t_env *env, char **origin_env, int argc)
{
	int		g_fd[2][2];
	pid_t	*pids;
	int		fd_in;
	int		save_stdin;
	int		i;

	i = 0;
	pids = malloc(sizeof(pid_t) * argc);
	save_stdin = dup(STDIN_FILENO);
	fd_in = 0;
	if (pipe(g_fd[0]) == -1 || pipe(g_fd[1]) == -1)
		exit(1);
	while (++i < argc)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			term(pids, i - 1, g_fd);
		if (!pids[i])
		{
			logic_pipe_execute(&pids[i], g_fd, i, argc);
			cmd = get_cmd(cmd, i);
			exit(find_comand(cmd, env, origin_env));
		}
		ebuchay_norma_sorry(g_fd, i, argc, pids);
		if (pipe(g_fd[i & 1]) == -1)
			term1(pids, i, g_fd);
	}
	dup2(save_stdin, 0);
	free (pids);
	return (0);
}