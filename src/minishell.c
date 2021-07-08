#include "../includes/minishell.h"

int	minishell(char *line, t_env **env)
{
	if (ft_checkline(line))
		return (0);
}

int	main(int argc, char **argv, char **envir)
{
	t_env	*env;
	t_env	*tmp;
	char	*buf;
	(void) argc;
	(void) argv;

	if (!ft_get_list_environments(envir, &env))
		ft_terminate("malloc error");
	while (1)
	{
		ft_minishell(readline("\e[1;31mminishell\xF0\x9F\x91\x80:\e[0;37m"), &env);
	}
	return (0);
}



//readline, rl_on_new_line, rl_replace_line, rl_redisplay, add_history