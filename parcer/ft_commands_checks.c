#include "../includes/minishell.h"

int	ft_comm_check(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		if ((tmp->cmd[0] == '<' || tmp->cmd[0] == '>') && tmp->args == NULL)
		{
			write(1, "<:\xF0\x9F\x91\x80:>syntax error\n", 21);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}