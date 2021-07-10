#include "includes/minishell.h"

int	comand_pwd(t_cmd *cmd, t_env *env)
{
	int i;
	t_env *tmp;

	tmp = ft_get_list_env("PWD", &env);
	i = 0;
	while (cmd->arg[i])
		free(cmd->arg[i++]);
	cmd->arg[0] = ft_strdup(tmp->value);
	t_cmd	*redirect;
	int		fd;
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
		ft_putendl_fd(cmd->arg[0], fd);
	}
	else
		ft_putendl_fd(cmd->arg[0], 1);
	return (0);
	
	return (0);
}