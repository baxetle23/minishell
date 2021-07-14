#include "../includes/minishell.h"
#include <unistd.h>

void	ft_get_signals(int id)
{
	if (id == SIGINT)
	{
	//	rl_on_new_line();
	//	rl_replace_line();
	//	rl_redisplay();
		printf("\x1b[2D");
		printf("\n");
	}
	if (id == SIGQUIT)
	{
		printf("\x1b[2D\n");
	}
}

int	ft_minishell(char *line, t_env **env, t_cmd **cmd)
{
	if (line == NULL)
	{
		printf("\x1b[2Dexit\n");
		exit(0);
	}
	if (line[0] != '\0')
	{
		add_history(line);
		if (ft_checkline(line, env, cmd))
			return (0);
	}
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

		signal(SIGINT, ft_get_signals);
		sigignore(SIGQUIT);
		//signal(SIGQUIT, ft_get_signals);

	while (1)
	{
		cmd = NULL;
		//ft_minishell(readline("\e[1;31mminishell\xF0\x9F\x91\x80:\e[0;37m"), &env, &cmd);
		//write(1 ,"\e[1;31mminishell\xF0\x9F\x91\x80:\e[0;37m", 29);
		//printf("-%s-", readline("\xF0\x9F\x91\x80:"));
		ft_minishell(readline(EYESES), &env, &cmd);
		//ft_minishell(readline("\x1b[1;37mminishell\xF0\x9F\x91\x80:"), &env, &cmd);
	}
	return (0);
}



//readline, rl_on_new_line, rl_replace_line, rl_redisplay, add_history