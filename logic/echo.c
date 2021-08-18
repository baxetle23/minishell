#include "../includes/minishell.h"

int	check_flags_echo(char *flag)
{
	int	i;

	i = 1;
	while (flag[i])
	{
		if (flag[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	comand_echo(t_cmd *cmd)
{
	int		fd;

	write(1, "test\n", 5);
	fd = find_file_des(cmd);
	if (fd < 0)
	{
		ft_putendl_fd("error open file", 2);
		return (1);
	}
	if (cmd->flags[1] && check_flags_echo(cmd->flags[1]))
		ft_putstr_fd(cmd->args[0], fd);
	else
		ft_putendl_fd(cmd->args[0], fd);
	return (0);
}
