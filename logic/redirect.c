#include "../includes/minishell.h"


//проверять открытие файлов и доступ к ним - выводить ошибкуte

t_cmd	*find_redirect(t_cmd *cmd)
{
	if (cmd->next)
	{
		if (!ft_strncmp_notregistr(">", cmd->next->cmd, ft_strlen(cmd->next->cmd)) ||
			!ft_strncmp_notregistr(">>", cmd->next->cmd, ft_strlen(cmd->next->cmd)))
			return (cmd->next);
	}
	return (NULL);
}

t_cmd *many_redirect(t_cmd *cmd)
{
	t_cmd *redirect;
	redirect = find_redirect(cmd);
	while(redirect)
	{
		if (redirect->next && find_redirect(redirect))
		{
			if (ft_strncmp(redirect->cmd, ">>", 3))
				open(redirect->args[0], O_CREAT | O_TRUNC, 0664);
			else
				open(redirect->args[0], O_CREAT, 0664);
			redirect = find_redirect(redirect);
			continue ;
		}
		return redirect;
	}
	return redirect;
}

int get_fd_redirecta(t_cmd *redirect)
{
	int fd;
	if (ft_strncmp(redirect->cmd, ">>", 3))
		fd = open(redirect->args[0], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	else
		fd = open(redirect->args[0], O_CREAT | O_WRONLY | O_APPEND, 0664);
	if (fd < 0)
	{
		printf("ERROR OPEN FILE\n");
		return (-1);
	}
	return fd;
}

int	find_file_des(t_cmd *cmd)
{
	t_cmd *redirect;
	redirect = find_redirect(cmd);
	while(redirect)
	{
		if (redirect->next && find_redirect(redirect))
		{
			if (ft_strncmp(redirect->cmd, ">>", 3))
				open(redirect->args[0], O_CREAT | O_TRUNC, 0664);
			else
				open(redirect->args[0], O_CREAT, 0664);
			redirect = find_redirect(redirect);
			continue ;
		}
		return get_fd_redirecta(redirect);
	}
	return 1;
}