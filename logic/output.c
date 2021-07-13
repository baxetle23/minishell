#include "../includes/minishell.h"

int	ft_putbuffer_fd(char **buffer, int fd, t_cmd *cmd)
{
	int i;
	i = 0;
	while(buffer[i])
	{
		ft_putstr_fd(buffer[i], fd);
		if (ft_strncmp_notregistr("echo", cmd->cmd, ft_strlen(cmd->cmd)))
			write(fd, "\n", 1);
		i++;
	}
	return (0);
}

int		output_to_fd(char **buffer, t_cmd *cmd)
{
	
	int		fd;
	t_cmd	*redirect;

//	print_comand_arg(cmd);
	redirect = many_redirect(cmd);
	if (redirect)
	{
		
		if (ft_strncmp(redirect->cmd, ">>", 3))
			fd = open(redirect->args[0], O_CREAT | O_TRUNC | O_WRONLY, 0664);
		else
		{
			fd = open(redirect->args[0], O_CREAT | O_WRONLY | O_APPEND, 0664);
			printf("%s\n", redirect->cmd);
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
