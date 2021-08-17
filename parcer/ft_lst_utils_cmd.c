#include "../includes/minishell.h"

int	ft_lst_cmd_length(t_cmd **cmd)
{
	t_cmd	*tmp;
	int		i;

	if (!cmd)
		return (0);
	i = 0;
	tmp = *cmd;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_cmd	*ft_lstnew_cmd(char *cmd, char **flags, char **args)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (0);
	new->cmd = cmd;
	new->flags = flags;
	new->args = args;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_cmd(t_cmd **lst, t_cmd *new)
{
	t_cmd	*buf;

	buf = *lst;
	if (!buf)
		*lst = new;
	else
	{
		while (buf->next != NULL)
			buf = buf->next;
		buf->next = new;
	}
}
