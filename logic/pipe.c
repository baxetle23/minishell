#include "../includes/minishell.h"

t_cmd *pipe_exist(t_cmd *cmd)
{
	while(cmd)
	{
		if (!ft_strcmp(cmd->cmd, "|"))
			return (cmd);
		cmd = cmd->next;
	}
	return (NULL);
}

t_cmd *next_pipe_exist(t_cmd *cmd)
{
	t_cmd* tmp;
	tmp = pipe_exist(cmd);
	if (tmp)
		return (pipe_exist(tmp->next));
	return (NULL);
}