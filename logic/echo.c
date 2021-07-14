#include "../includes/minishell.h"

int	comand_echo(t_cmd *cmd)
{
	char	**buffer;
	char	*tmp;

	int i = 0;
	while (cmd->args[i])
		i++;

	buffer = (char **)malloc(sizeof(char *) * (i + 1));
	buffer[i] = NULL;
	i = 0;
	while (cmd->args[i])
	{
		buffer[i] = ft_strdup(cmd->args[i]);
		i++;
	}
	if (ft_strcmp("-n", cmd->flags[1]))
	{
		tmp = buffer[i - 1];
		buffer[i - 1] = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	output_to_fd(buffer, cmd);
	return (0);
}