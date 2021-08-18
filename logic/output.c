#include "../includes/minishell.h"

int free_buffer(char **buffer)
{
	int i = 0;
	if (buffer == NULL)
		return (1);
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
	ft_putendl_fd("test1", 1);

	return (1);
}

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
	free_buffer(buffer);
	return (0);
}

int	output_to_fd(char **buffer, t_cmd *cmd)
{
	int		fd;
	fd = find_file_des(cmd);
	if (fd < 0) {
		ft_putendl_fd("error open file", 2);
		return (1);
	}
	ft_putbuffer_fd(buffer, fd, cmd);
	return (0);
}
