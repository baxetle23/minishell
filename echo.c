#include "includes/minishell.h"

int	comand_echo(t_cmd *cmd)
{
	char	**buffer;
	char	*tmp;
	int		fd;

	if (ft_strncmp("-n", cmd->flags[1], ft_strlen(cmd->flags[1])))
	{
		tmp = cmd->arg[0];
		cmd->arg[0] = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	buffer = (char **)malloc(sizeof(char *) * 2);
	buffer[1] = NULL;
	buffer[0] = ft_strdup(cmd->arg[0]);
	output_to_fd(buffer, cmd);
	return (0);
}