#include "../includes/minishell.h"

void	ft_get_signals(int id)
{
	if (id == SIGINT)
	{
	//	rl_on_new_line();
	//	rl_redisplay();
	//	write(1, EYESES, 5);
	//	rl_replace_line("", 0);
	//	rl_on_new_line();
		
	//	rl_replace_line("", 0);
		write(1, "\n", 2);
	//	rl_redisplay();
		
	//	printf(EYESES);

	//	rl_on_new_line();
		
	//	rl_redisplay();
	//	printf("\x1b[2D");
	}
	if (id == SIGQUIT)
	{
		printf("\x1b[2D\n");
	}
}

int	ft_only_tabs(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!((line[i] >= 9 && line[i] <= 13) || line[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	ft_minishell(char *line, t_env **env, t_cmd **cmd, char **envir)
{
	if (line == NULL)
	{
		printf("\x1b[2Dexit\n");
		exit(0);
	}
	if (line[0] != '\0' && !ft_only_tabs(line))
	{
		add_history(line);
		if (ft_checkline(line, env, cmd, envir))
			return (0);
	}
	else
		free (line);
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
		ft_minishell(readline(EYESES), &env, &cmd, envir);
	}
	return (0);
}

//readline, rl_on_new_line, rl_replace_line, rl_redisplay, add_history