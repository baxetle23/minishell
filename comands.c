#include "includes/minishell.h"

int	comand_echo(t_cmd *cmd)
{
	t_cmd	*redirect;
	char	*tmp;
	int		fd;

	if (ft_strncmp("-n", cmd->flags[1], ft_strlen(cmd->flags[1])))
	{
		tmp = cmd->arg[0];
		cmd->arg[0] = ft_strjoin(tmp, "\n");
		free(tmp);
	}
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
		ft_putstr_fd(cmd->arg[0], fd);
	}
	else
		ft_putstr_fd(cmd->arg[0], 1);
	return (0);
}

int	comand_cd(t_cmd *cmd)
{
	return (0);
}

int	comand_pwd(t_cmd *cmd)
{
	return (0);
}

int	comand_export(t_cmd *cmd)
{
	return (0);
}

int	comand_unset(t_cmd *cmd)
{
	return (0);
}

int	comand_env(t_cmd *cmd)
{
	return (0);
}

int	comand_exit(t_cmd *cmd)
{
	return (0);
}

int	comand_redirect(t_cmd *cmd)
{
	return (0);
}