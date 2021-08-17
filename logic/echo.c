#include "../includes/minishell.h"

int	ft_strcmp_echo(char * flag)
{
	int	i;

	i = 0;
	if (flag == NULL) {
		return (0);
	}
	while(flag[i]) {
		if (flag[i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (flag[i] == 'n')
		{
			i++;
			continue;
		}
		return (0);
	}
	if (i >= 1)
		return (1);
	else
		return (0);
}

int get_memory_for_flag(char * flag)
{
	int i;

	i = 0;
	if (flag == NULL) {
		return (0);
	}
	while(flag[i]) {
		if (flag[i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (flag[i] == 'n')
		{
			i++;
			continue;
		}
		return (1);
	}
	if (i >= 1)
		return (0);
	else
		return (1);
}

int	comand_echo(t_cmd *cmd)
{
	char	**buffer;
	char	*tmp;
	int		flag;

	int i = 0;
	flag = 0;
	while (cmd->args[i])
		i++;
	flag = get_memory_for_flag(cmd->flags[1]);
	buffer = (char **)malloc(sizeof(char *) * (i + 1 + flag));
	buffer[i + flag] = NULL;
	i = 0;
	if (flag)
		buffer[0] = ft_strdup(cmd->flags[1]);
	while (cmd->args[i])
	{
		buffer[i + flag] = ft_strdup(cmd->args[i]);
		i++;
	}
	if (!ft_strcmp_echo(cmd->flags[1]))
	{
		tmp = buffer[i - 1 + flag];
		buffer[i - 1 + flag] = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	return (output_to_fd(buffer, cmd));
}