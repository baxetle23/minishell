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

int	ft_norm_flag_minus_n(char *flag)
{
	int	i;

	i = 1;
	while (flag[i])
		if (flag[i++] != 'n')
			return (0);
	return (1);
}

char	*ft_check_echo_flags(t_cmd *cmd)
{
	char	*res;
	int		i;
	
	if (cmd->flags[1] == NULL)
		return (NULL);
	res = NULL;
	i = 1;
	while (cmd->flags[i] && ft_norm_flag_minus_n(cmd->flags[i]))
		i++;
	while (cmd->flags[i])
	{
		res = ft_strjoin_m(res, ft_strdup(cmd->flags[i]));
		if (cmd->flags[i + 1])
			res = ft_strjoin_m(res, ft_strdup(" "));
		i++;
	}
	if (cmd->args[0] && res)
		res = ft_strjoin_m(res, ft_strdup(" "));
	return (res);
}

void	ft_echo_fill(t_cmd *cmd)
{
	char	**res_flags;
	char	**res_args;
	char	*tmp_arg;
	int		i;

	if (cmd->args[0] || cmd->flags[1])
		res_args = (char **)malloc(sizeof(char *) + 1);
	else
		return ;
	
	res_args[0] = ft_check_echo_flags(cmd);
	res_args[1] = NULL;
	i = 0;
	while (cmd->args[i])
	{
		write(1, "!", 1);
		res_args[0] = ft_strjoin_m(res_args[0], ft_strdup(cmd->args[i]));
		if (cmd->args[i + 1])
			res_args[0] = ft_strjoin_m(res_args[0], ft_strdup(" "));
		i++;
	}
	ft_free_mas(cmd->args);
	cmd->args = res_args;
}

int	ft_comm_check(t_cmd **cmd)
{
	int		i;
	t_cmd	*tmp;
	t_cmd	*last_cmd;
	tmp = *cmd;
	
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
		else if (!ft_strncmp_notregistr(tmp->cmd, "echo", 4))
		{
			ft_echo_fill(tmp);
		}
		tmp = tmp->next;
	}
	return (1);
}