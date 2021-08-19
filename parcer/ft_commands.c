#include "../includes/minishell.h"

char	**ft_get_flags(t_words **words, int i, int flags_c)
{
	char	**res;
	t_words	*tmp;

	tmp = *words;
	while (i--)
		tmp = tmp->next;
	res = (char **)malloc(sizeof(char *) * (flags_c + 1));
	i = 0;
	while (i < flags_c)
	{
		if (ft_is_redirect(tmp))
		{
			tmp = tmp->next;
			if (tmp && !ft_is_pipe(tmp))
				tmp = tmp->next;
		}
		else
		{
			res[i++] = ft_strdup(tmp->word);
			tmp = tmp->next;
		}
	}
	res[i] = NULL;
	return (res);
}

char	**ft_get_args(t_words **words, int i, int flags_c, int args_c)
{
	char	**res;
	t_words	*tmp;

	tmp = ft_skip_redir_i_flags(words, i, flags_c);
	res = (char **)malloc(sizeof(char *) * (args_c + 1));
	i = 0;
	while (i < args_c)
	{
		if (ft_is_redirect(tmp))
		{
			tmp = tmp->next;
			if (tmp && !ft_is_pipe(tmp))
				tmp = tmp->next;
		}
		else
		{
			res[i++] = ft_strdup(tmp->word);
			tmp = tmp->next;
		}
	}
	res[i] = NULL;
	return (res);
}

void	ft_get_all_things(t_words **words, t_cmd **cmd_input,
		int *start, char *command)
{
	int		flags_c;
	int		args_c;
	t_cmd	*cmd;
	char	*tmp;
	int		old_st;

	old_st = *start;
	flags_c = ft_get_count_flags(words, *start);
	args_c = ft_get_count_args(words, *start, flags_c);
	if (args_c || flags_c)
	{
		cmd = ft_lstnew_cmd(command,
				ft_get_flags(words, *start, flags_c),
				ft_get_args(words, *start, flags_c, args_c), 0);
		tmp = cmd->cmd;
		cmd->cmd = ft_strdup(cmd->flags[0]);
		free(tmp);
		ft_lstadd_cmd(cmd_input, cmd);
	}
	else
		free(command);
	ft_add_all_redirects(words, old_st, cmd_input);
	*start = *start + flags_c + args_c + ft_count_red(words, old_st);
}

void	ft_get_comm(t_words **words, t_cmd **cmd_input, int start, int old_st)
{
	t_cmd	*cmd;
	char	*command;

	cmd = NULL;
	start = 0;
	while (start < ft_lst_words_length(words))
	{
		old_st = start;
		command = ft_get_cmd_by_start(words, start);
		if (command[0] == '|' && ft_check_acitve(words, start))
		{
			start = start + 1;
			cmd = ft_lstnew_cmd(command, get_empty_m(), get_empty_m(), 1);
			ft_lstadd_cmd(cmd_input, cmd);
		}
		else
			ft_get_all_things(words, cmd_input, &start, command);
	}
}
