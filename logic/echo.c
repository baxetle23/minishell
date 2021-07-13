#include "../includes/minishell.h"

int	comand_echo(t_cmd *cmd)
{
	char	**buffer;
	char	*tmp;

write(1, "testecho\n", 9);
	if (ft_strcmp("-n", cmd->flags[1]))
	{
		write(1, "testecho\n", 9);
		tmp = cmd->args[0];
		cmd->args[0] = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	buffer = (char **)malloc(sizeof(char *) * 2);
	buffer[1] = NULL;
	buffer[0] = ft_strdup(cmd->args[0]);
	
	output_to_fd(buffer, cmd);
	return (0);
}