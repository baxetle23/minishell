#include "includes/minishell.h"

int	ft_putbuffer_fd(char **buffer, int fd, t_cmd *cmd)
{
	int i;
	i = 0;
	while(buffer[i])
	{
		ft_putstr_fd(buffer[i], fd);
		if (ft_strncmp_notregistr("echo", cmd->name, ft_strlen(cmd->name)))
			write(fd, "\n", 1);
		i++;
	}
	return (0);
}

int		output_to_fd(char **buffer, t_cmd *cmd)
{
	int		fd;
	t_cmd	*redirect;

	redirect = many_redirect(cmd);
	if (redirect)
	{
		if (ft_strncmp(redirect->name, ">>", 3))
			fd = open(redirect->arg[0], O_CREAT | O_TRUNC | O_WRONLY, 0664);
		else
		{
			fd = open(redirect->arg[0], O_CREAT | O_WRONLY | O_APPEND, 0664);
			printf("%s\n", redirect->name);
		}
		if (fd < 0)
		{
			printf("ERROR OPEN FILE\n");
			return (1);
		}
		ft_putbuffer_fd(buffer, fd, cmd);
	}
	else
		ft_putbuffer_fd(buffer, 1, cmd);
	return (0);
}
