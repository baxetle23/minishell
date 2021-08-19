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
	exit(g_status_error);
}

void	init_for_pipe(int *i, pid_t **pids, int *save, int argc)
{
	*i = 0;
	*pids = malloc(sizeof(pid_t) * argc);
	*save = dup(STDIN_FILENO);
}
