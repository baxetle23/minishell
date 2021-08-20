#include "../includes/minishell.h"

int	check_many_arg_ex(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->args[0][++i])
	{
		if ((cmd->args[0][i] == '-' && i == 0) || ft_isdigit(cmd->args[0][i]))
			continue ;
		g_status_error = 255;
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(cmd->args[0], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit (g_status_error);
	}
	ft_putendl_fd("exit: too many arguments", 2);
	g_status_error = 1;
	return (g_status_error);
}

void	check_number_exit(char *number)
{
	int	i;

	if (ft_strlen(number) > 20)
	{
		g_status_error = 255;
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(number, 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit (g_status_error);
	}
	i = ft_atoi(number);
	if (i > 255)
		exit(WEXITSTATUS(i) - 1);
	else
		exit(i);
}

void	check_one_arg_ex(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->args[0][++i])
	{
		if ((cmd->args[0][i] == '-' && i == 0) || ft_isdigit(cmd->args[0][i]))
			continue ;
		g_status_error = 255;
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(cmd->args[0], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit (g_status_error);
	}
	check_number_exit(cmd->args[0]);
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
		return (check_many_arg_ex(cmd));
	else if (cmd->args && cmd->args[0])
		check_one_arg_ex(cmd);
	else
		exit(g_status_error);
	return (0);
}
