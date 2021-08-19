#include "../includes/minishell.h"

t_words	*ft_skip_redir(t_words **words, int *i)
{
	t_words	*tmp;

	tmp = *words;
	while ((*i)--)
		tmp = tmp->next;
	while (tmp && (ft_is_redirect(tmp)))
	{
		tmp = tmp->next;
		if (tmp && !ft_is_pipe(tmp))
			tmp = tmp->next;
	}
	*i = 0;
	if (tmp && !ft_is_pipe(tmp) && !(ft_is_redirect(tmp)))
	{
		tmp = tmp->next;
		*i = *i + 1;
	}
	return (tmp);
}

t_words	*ft_skip_redir_i_flags(t_words **words, int i, int flags_c)
{
	t_words	*tmp;

	tmp = *words;
	while (i--)
	{
		tmp = tmp->next;
	}
	i = 0;
	while (flags_c)
	{
		if (ft_is_redirect(tmp))
		{
			tmp = tmp->next;
			if (tmp && !ft_is_pipe(tmp))
				tmp = tmp->next;
		}
		else
		{
			tmp = tmp->next;
			flags_c--;
		}
	}
	return (tmp);
}
