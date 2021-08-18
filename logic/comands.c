#include "../includes/minishell.h"

int	comand_exit(t_cmd *cmd)
{
	(void)cmd;
	ft_putendl_fd("exit", 1);
	exit(g_status_error);
}
