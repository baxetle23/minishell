#include "../includes/minishell.h"

int	ft_minishell(char *line, t_env **env, t_cmd **cmd)
{
	if (line[0] != '\0')
		add_history(line);
	if (ft_checkline(line, env, cmd))
		return (0);
	return (1);
}

int	main(int argc, char **argv, char **envir)
{
	t_env	*env;
	t_cmd	*cmd;
	(void) argc;
	(void) argv;

	if (!ft_get_list_environments(envir, &env))
		ft_terminate("malloc error");
	while (1)
	{
		//ft_minishell(readline("\e[1;31mminishell\xF0\x9F\x91\x80:\e[0;37m"), &env, &cmd);
		//write(1 ,"\e[1;31mminishell\xF0\x9F\x91\x80:\e[0;37m", 29);
		ft_minishell(readline("\xF0\x9F\x91\x80:"), &env, &cmd);
	}
	return (0);
}



//readline, rl_on_new_line, rl_replace_line, rl_redisplay, add_history