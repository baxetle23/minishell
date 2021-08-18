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
	tmp = NULL;
	flag = 0;
	if (cmd->args)
		while (cmd->args[i])
			i++;
	if (cmd->flags && cmd->flags[0])
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
	write(1, "test\n", 5);
	if (!ft_strcmp_echo(cmd->flags[1]))
	{
		write(1, "test33\n", 7);
		printf("i = %d, flag = %d, buffer = %s\n", i, flag, buffer[i - 1 + flag]);
		if (buffer[i - 1 + flag] == NULL)
		{
			buffer[i - 1 + flag] = ft_strdup("\n");
			return (output_to_fd(buffer, cmd));
		}
		tmp = buffer[i - 1 + flag];
		buffer[i - 1 + flag] = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	write(1, "test22\n", 7);

	return (output_to_fd(buffer, cmd));
}