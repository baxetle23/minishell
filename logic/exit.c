#include "../includes/minishell.h"

int	check_many_arg_ex(t_cmd *cmd)
{
	(void)cmd;
	return (0);
}

int	check_one_arg_ex(t_cmd *cmd)
{
	int	fd;

	fd = ft_atoi(cmd->args[0]);
	if (fd > 255)
		exit(WEXITSTATUS(fd) - 1);
	else
		exit(fd);
}

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
	if (cmd->args && cmd->args[0] && cmd->args[1])
		check_many_arg_ex(cmd);
	else if (cmd->args && cmd->args[0])
		check_one_arg_ex(cmd);
	else
		exit(g_status_error);
	return (0);
}
