//checks for syntax errors

#include "../includes/minishell.h"

int	ft_print_syntaxerror(void)
{
	write(1, "!\xF0\x9F\x91\x80!: syntax error\n", 21);
	return (0);
}

int	ft_create_new_file(t_cmd *cur, int i)
{
	char	*line;
	char	*name;
	char	*num;
	int		fd;

	num = ft_itoa(i);	
	name = ft_strjoin(FILENAME, num);
	free(num);
	fd = open(name, O_CREAT | O_RDWR, 0777);
	line = readline("> ");
	while (line && ft_strcmp(cur->args[0], line))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline("> ");
	}
	free(line);
	free(cur->cmd);
	cur->cmd = ft_strdup("<");
	free(cur->args[0]);
	cur->args[0] = name;
	close(fd);
	return (0);
}

int	ft_comm_check(t_cmd **cmd)
{
	int		i;
	t_cmd	*tmp;
	t_cmd	*last_cmd;
	tmp = *cmd;
	
/*	if ((tmp->cmd[0]) == '|')
	{
		printf("\n!%s!\n", tmp->cmd);
		return (ft_print_syntaxerror());
	}*/

	while (tmp)
	{
		if ((tmp->cmd[0] == '<' || tmp->cmd[0] == '>') && tmp->active && tmp->args[0] == NULL)
			return (ft_print_syntaxerror());
		if ((tmp->cmd[0]) == '|' && tmp->active && (tmp == *cmd || (last_cmd->cmd[0] == '|' && last_cmd->active)))
			return (ft_print_syntaxerror());
		last_cmd = tmp;
		tmp = tmp->next;
	}
	tmp = *cmd;
	i = 1;
	while (tmp)
	{
		if (ft_strcmp(tmp->cmd, "<<") == 0)
			{
				ft_create_new_file(tmp, i);
				i++;
			}
		tmp = tmp->next;
	}
	return (1);
}