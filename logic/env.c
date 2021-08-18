#include "../includes/minishell.h"

void	print_envp(t_env *envp, int fd)
{
	t_env	*tmp;

	tmp = envp;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, fd);
			write(fd, "=", 1);
			ft_putendl_fd(tmp->value, fd);
		}
		tmp = tmp->next;
	}
}

int	comand_env(t_cmd *cmd, t_env *env)
{
	int	fd;

	fd = find_file_des(cmd);
	if (fd < 0)
		return (1);
	print_envp(env, fd);
	return (0);
}
