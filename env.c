#include "includes/minishell.h"

int	count_arg_env(t_cmd *cmd)
{
	int i;

	i = 0;
	while (cmd->arg[i])
		i++;
	if (i == 0)
		return (0);
	return(1);
}

int	ft_putenv_fd(t_env *env, int fd,t_cmd *cmd)
{
	dup2(fd, STDOUT_FILENO);
	close(fd);
	while(env)
	{
		printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
	return (0);
}

int	output_to_fd_for_env(t_env *env, t_cmd *cmd)
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
		ft_putenv_fd(env, fd, cmd);
	}
	else
		ft_putenv_fd(env, 1, cmd);
	return (0);
}

int	comand_env(t_cmd *cmd, t_env *env)
{
	output_to_fd_for_env(env, cmd);
	return (0);
}