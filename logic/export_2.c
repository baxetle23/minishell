#include "../includes/minishell.h"

int	compare_env_element(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	swap_elem(t_env **tmp, char **tmp2, int *flag)
{
	*tmp2 = (*tmp)->key;
	(*tmp)->key = (*tmp)->next->key;
	(*tmp)->next->key = *tmp2;
	*tmp2 = (*tmp)->value;
	(*tmp)->value = (*tmp)->next->value;
	(*tmp)->next->value = *tmp2;
	*flag = 1;
}

int	sort_env(t_env *env)
{
	t_env	*start;
	t_env	*tmp;
	char	*tmp2;
	int		flag;

	start = env;
	while (start->next)
	{
		flag = 0;
		tmp = start;
		while (tmp->next)
		{
			if (compare_env_element(tmp->key, tmp->next->key) > 0)
				swap_elem(&tmp, &tmp2, &flag);
			tmp = tmp->next;
		}
		if (flag == 0)
			break ;
	}
	return (0);
}

void	print_sort_envp(t_env *envp, int fd)
{
	t_env	*tmp;

	tmp = envp;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd("declare -x ", fd);
			ft_putstr_fd(tmp->key, fd);
			ft_putstr_fd("=\"", fd);
			ft_putstr_fd(tmp->value, fd);
			ft_putstr_fd("\"\n", fd);
		}
		else
		{
			ft_putstr_fd("declare -x ", fd);
			ft_putstr_fd(tmp->key, fd);
			ft_putstr_fd("=\"\n", fd);
		}
		tmp = tmp->next;
	}
}
