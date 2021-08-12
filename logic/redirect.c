#include "../includes/minishell.h"

t_cmd	*find_redirect(t_cmd *cmd)
{
	while (cmd->next)
	{
		if (!ft_strncmp_notregistr("<", cmd->next->cmd, ft_strlen(cmd->next->cmd)) ||
			!ft_strncmp_notregistr("<<", cmd->next->cmd, ft_strlen(cmd->next->cmd)))
		{
			cmd = cmd->next;
			continue ;
		}
		break ;
	}
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
			{
				if (open(redirect->args[0], O_CREAT | O_TRUNC, 0664))
					return NULL;
			}
			else
			{
				if (open(redirect->args[0], O_CREAT, 0664))
					return NULL;
			}
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
		ft_putstr_fd(redirect->args[0], 2);
		ft_putendl_fd(": Permission denied", 2);
		return (-1);
	}
	return fd;
}

int	find_file_des(t_cmd *cmd)
{
	int	fd;
	t_cmd *redirect;

	redirect = find_redirect(cmd);
	while(redirect)
	{
		if (redirect->next && find_redirect(redirect))
		{
			if (ft_strncmp(redirect->cmd, ">>", 3))
			{
				if (open(redirect->args[0], O_CREAT | O_TRUNC, 0664) < 0)
				{
					ft_putstr_fd(redirect->args[0], 2);
					ft_putendl_fd(": Permission denied", 2);
					return (-1);
				}
			}
			else
			{
				if (open(redirect->args[0], O_CREAT, 0664) < 0) 
				{
					ft_putstr_fd(redirect->args[0], 2);
					ft_putendl_fd(": Permission denied", 2);
					return (-1);
				}
			}
			redirect = find_redirect(redirect);
			continue ;
		}
		return get_fd_redirecta(redirect);
	}
	return 1;
}

int	comand_redirect(t_cmd *cmd)
{
	if (cmd->args[0] == NULL)
	{
		ft_putendl_fd(" syntax error near unexpected token `newline'", 2);
		return (1);
	}
	if (ft_strncmp(cmd->cmd, ">>", 3))
	{
		if (open(cmd->args[0], O_CREAT | O_TRUNC, 0664) < 0)
		{
			ft_putstr_fd(cmd->args[0], 2);
			ft_putendl_fd(": Permission denied", 2);
			return (-1);
		}
	}
	else
	{
		if (open(cmd->args[0], O_CREAT, 0664) < 0)
		{
			ft_putstr_fd(cmd->args[0], 2);
			ft_putendl_fd(": Permission denied", 2);
			return (-1);
		}
	}
	find_file_des(cmd);
	return (0);
}