#include "../includes/minishell.h"

int	comand_exve(t_cmd *cmd, t_env *envp, char **o_env)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		exit (1);
	if (pid == 0)
		call_execve_process(cmd, envp, o_env);
	wait(&g_status_error);
	g_status_error = WEXITSTATUS(g_status_error);
	return (g_status_error);
}

void	free_memory(char **split1, char **split2)
{
	int	i;

	i = 0;
	while (split1[i])
		free(split1[i++]);
	i = 0;
	while (split2[i])
		free(split2[i++]);
	free(split2);
	free(split1);
}
