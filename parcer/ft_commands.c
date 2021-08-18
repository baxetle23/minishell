#include "../includes/minishell.h"

char	**ft_get_flags(t_words **words, int start, int flags_count)
{
	char	**res;
	t_words	*tmp;
	int		i;

	tmp = *words;
	i = start;
	while (i--)
		tmp = tmp->next;
	res = (char **)malloc(sizeof(char *) * (flags_count + 1));
	i = 0;
	while (i < flags_count)
	{
		if ((tmp->word[0] == '<' || tmp->word[0] == '>') && tmp->active)
		{
			tmp = tmp->next;
			if (tmp && !(tmp->word[0] == '|' && tmp->active))
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

char	**ft_get_args(t_words **words, int start, int flags_count, int args_count)
{
	char	**res;
	t_words	*tmp;
	int		i;

	tmp = *words;
	i = start;

	while (i--)
	{
		tmp = tmp->next;
	}
	i = 0;
	while (flags_count)
	{
		if ((tmp->word[0] == '<' || tmp->word[0] == '>') && tmp->active)
		{
			tmp = tmp->next;
			if (tmp && !(tmp->word[0] == '|' && tmp->active))
				tmp = tmp->next;
		}
		else
		{
			tmp = tmp->next;
			flags_count--;
		}
	}

	res = (char **)malloc(sizeof(char *) * (args_count + 1));
	i = 0;
	while (i < args_count)
	{
		if ((tmp->word[0] == '<' || tmp->word[0] == '>') && tmp->active)
		{
			tmp = tmp->next;
			if (tmp && !(tmp->word[0] == '|' && tmp->active))
				tmp = tmp->next;
		}
		else{
			res[i++] = ft_strdup(tmp->word);
			tmp = tmp->next;
		}
	}
	//write(1, "yep!", 4);
	res[i] = NULL;
	return (res);
}

int	ft_get_count_flags(t_words **words, int	list_start)
{
	t_words	*tmp;
	int		i;

	tmp = *words;
	i = list_start; //можно поменять на еще +1 и перейти на самый первый жлемент, с которого уже можно считать
	while (i--)
		tmp = tmp->next;
	while (tmp && ((tmp->word[0] == '<' || tmp->word[0] == '>') && tmp->active))
	{
		tmp = tmp->next;
		if (tmp && !(tmp->word[0] == '|' && tmp->active))
				tmp = tmp->next;
	}
	i = 0;
	if (tmp && !(tmp->word[0] == '|' && tmp->active) && !((tmp->word[0] == '<' || tmp->word[0] == '>') && tmp->active))
	{
		tmp = tmp->next;
		i++;
	}
	while (tmp && !(tmp->word[0] == '|' && tmp->active) && (((tmp->word[0] == '<' || tmp->word[0] == '>') && tmp->active) || tmp->word[0] == '-'))
	{
		//printf("proba i %d\n", i);
		if ((tmp->word[0] == '<' || tmp->word[0] == '>') && tmp->active)
		{
			tmp = tmp->next;
			if (tmp && !(tmp->word[0] == '|' && tmp->active))
				tmp = tmp->next;
		}
		else
		{
			i++;
			tmp = tmp->next;
		}
		
	}
	return (i);
}

int	ft_get_count_args(t_words **words, int	list_start, int flags_count) //исправить редирект(чтобы аргументы добавлялись)
{
	t_words	*tmp;
	int		i;

	tmp = *words;
	i = list_start;
	while (i--)
	{
		tmp = tmp->next;
	}
	i = 0;
	while (flags_count)
	{
		if ((tmp->word[0] == '<' || tmp->word[0] == '>') && tmp->active)
		{
			tmp = tmp->next;
			if (tmp && !(tmp->word[0] == '|' && tmp->active))
				tmp = tmp->next;
		}
		else
		{
			tmp = tmp->next;
			flags_count--;
		}
	}
	while (tmp && !(tmp->word[0] == '|' && tmp->active))
	{
		if ((tmp->word[0] == '<' || tmp->word[0] == '>') && tmp->active)
		{
			tmp = tmp->next;
			if (tmp && !(tmp->word[0] == '|' && tmp->active))
				tmp = tmp->next;
		}
		else
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

void	ft_get_commands(t_words **words, char *line, t_cmd **cmd_input)
{
	(void)	line;
	t_cmd	*cmd;
	t_cmd	*start_cmd;
	char	*command;
	char	*tmp;
	int		flags_count;
	int		args_count;
	int		start;
	int		old_start;

	//start_cmd = *cmd_input;
	cmd = NULL; // can be delete;
	start = 0;
	while (start < ft_lst_words_length(words))
	{
		old_start = start;
		//printf("\nstart from: %d\n", start);
	//	if (ft_strcmp(ft_get_cmd_by_start(words, start), "|"))
	    command = ft_get_cmd_by_start(words, start);
		//printf("comand: %s\n", command);
		
		if (command[0] == '|' && ft_check_acitve(words, start))
		{
			start = start + 1;
			cmd = ft_lstnew_cmd(command, get_empty_m(), get_empty_m(), 1);
			ft_lstadd_cmd(cmd_input, cmd);
		}
		else
		{
			flags_count = ft_get_count_flags(words, start);
			//printf("count of flags(-): %d\n", flags_count);
		
			args_count = ft_get_count_args(words, start, flags_count);
			//printf("count of args(-): %d\n", args_count);
			
			if (args_count || flags_count)
			{
				cmd = ft_lstnew_cmd(command,
					ft_get_flags(words, start, flags_count),
					ft_get_args(words, start, flags_count, args_count), 0);
				tmp = cmd->cmd;
				cmd->cmd = ft_strdup(cmd->flags[0]);
				free(tmp);
				ft_lstadd_cmd(cmd_input, cmd);
			}
			else
				free(command);
			//printf("count of red: %d\n", ft_count_red(words, start));
			ft_add_all_redirects(words, old_start, cmd_input);

			start = start + flags_count + args_count + ft_count_red(words, old_start);
		}
		//printf("next start from: %d\n", start);
	}
	//printf("\nPRINT\n");
//	ft_print_lst_cmds(cmd_input);
//	ft_lstclear_cmds(&start_cmd);
}