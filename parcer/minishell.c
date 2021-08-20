#include "../includes/minishell.h"

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
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		write(1, "exit\n", 5);
		exit(g_status_error);
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
	while (1)
	{
		ft_siginit();
		cmd = NULL;
		ft_minishell(readline(EYESES), &env, &cmd, envir);
	}
	return (0);
}
