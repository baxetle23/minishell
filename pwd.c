#include "includes/minishell.h"

int	comand_pwd(t_cmd *cmd, t_env *env)
{
	int i;
	t_env *tmp;
	char	**buffer;

	tmp = ft_get_list_env("PWD", &env);
	i = 0;
	while (cmd->arg[i])
		free(cmd->arg[i++]);
	cmd->arg[0] = ft_strdup(tmp->value);
	buffer = (char **)malloc(sizeof(char *) * 2);
	buffer[1] = NULL;
	buffer[0] = ft_strdup(cmd->arg[0]);
	output_to_fd(buffer, cmd);
	return (0);
}