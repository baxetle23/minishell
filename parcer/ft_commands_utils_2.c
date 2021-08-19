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

int	ft_get_count_flags(t_words **words, int	i)
{
	t_words	*tmp;

	tmp = ft_skip_redir(words, &i);
	while (tmp && !ft_is_pipe(tmp) && ((ft_is_redirect(tmp))
			|| tmp->word[0] == '-'))
	{
		if (ft_is_redirect(tmp))
		{
			tmp = tmp->next;
			if (tmp && !ft_is_pipe(tmp))
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

int	ft_get_count_args(t_words **words, int	i, int flags_c)
{
	t_words	*tmp;

	tmp = ft_skip_redir_i_flags(words, i, flags_c);
	i = 0;
	while (tmp && !ft_is_pipe(tmp))
	{
		if (ft_is_redirect(tmp))
		{
			tmp = tmp->next;
			if (tmp && !ft_is_pipe(tmp))
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
