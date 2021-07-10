#include "includes/minishell.h"


//проверять открытие файлов и доступ к ним - выводить ошибкуte

t_cmd	*find_redirect(t_cmd *cmd)
{
	if (!ft_strncmp_notregistr(">", cmd->next->name, ft_strlen(cmd->next->name)) ||
		!ft_strncmp_notregistr(">>", cmd->next->name, ft_strlen(cmd->next->name)))
		return (cmd->next);
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
			if (ft_strncmp(redirect->name, ">>", 3))
				open(redirect->arg[0], O_CREAT | O_TRUNC, 0664);
			else
				open(redirect->arg[0], O_CREAT, 0664);
			redirect = find_redirect(redirect);
			continue ;
		}
		return redirect;
	}
	return redirect;
}