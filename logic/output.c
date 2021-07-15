#include "../includes/minishell.h"

int	ft_putbuffer_fd(char **buffer, int fd, t_cmd *cmd)
{
	int i;
	i = 0;
	while(buffer[i])
	{
		ft_putstr_fd(buffer[i], fd);
		if (!ft_strncmp_notregistr("echo", cmd->cmd, ft_strlen(cmd->cmd)))
			if (buffer[i + 1] != NULL)
				write(fd, " ", 1);
		i++;
	}
	return (0);
}

int		output_to_fd(char **buffer, t_cmd *cmd)
{
	int		fd;
	fd = find_file_des(cmd);
	ft_putbuffer_fd(buffer, fd, cmd);
	return (0);
}
