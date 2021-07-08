#include "includes/minishell.h"

t_cmd	*find_redirect(t_cmd *cmd)
{
	if (!ft_strncmp_notregistr(">", cmd->next->name, ft_strlen(cmd->next->name)))
		return (cmd->next);
	return (NULL);
}