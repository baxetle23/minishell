#include "../includes/minishell.h"

t_cmd *pipe_exist(t_cmd *cmd)
{
	while(cmd)
	{
		if (!ft_strcmp(cmd->cmd, "|"))
			return (cmd);
		cmd = cmd->next;
	}
	return (NULL);
}

t_cmd *next_pipe_exist(t_cmd *cmd)
{
	t_cmd* tmp;
	tmp = pipe_exist(cmd);
	if (tmp)
		return (pipe_exist(tmp->next));
	return (NULL);
}

int first_step(int *fd, t_cmd *cmd, t_env *env, char **origin_env)
{
	printf("first step\nname comand - %s\n", cmd->cmd);
	dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
	find_comand(cmd, env, origin_env);
	exit(0);
}

int	middle_step(int *fd, t_cmd *cmd, t_env *env, char **origin_env)
{
	dup2(fd[1], 1);
	dup2(fd[0], 0);
	close(fd[1]);
	close(fd[0]);
	find_comand(cmd, env, origin_env);
	exit(0);
}

int last_step(int *fd, t_cmd *cmd, t_env *env, char **origin_env)
{
	printf("last step\nname comand - %s\n", cmd->cmd);
	dup2(fd[0], 0);
	close(fd[1]);
	close(fd[0]);
	find_comand(cmd, env, origin_env);
	exit(0);
}

int count_pipe(t_cmd *cmd)
{
	int i = 0;
	while (cmd)
	{
		if (!ft_strcmp(cmd->cmd, "|"))
			i++;
		cmd = cmd->next;
	}
	return (i);
}

int logic_pipe(t_cmd *cmd, t_env *env, char **origin_env)
{
	t_cmd	*tmp_cmd;
	tmp_cmd = cmd;
	int fd[2];
	int	pid;
	pipe(fd);	
	pid = fork();
	if (pid == 0)
		first_step(fd, cmd, env, origin_env);
	wait(NULL);

	int i = 1;
	while (i < count_pipe(cmd))
	{
		tmp_cmd = pipe_exist(tmp_cmd)->next;
		printf("middle step\nname comand - %s\n", tmp_cmd->cmd);
		pid = fork();
		if (pid == 0)
			middle_step(fd, tmp_cmd, env, origin_env);
		wait(NULL);
		i++;
	}

	tmp_cmd = pipe_exist(tmp_cmd)->next;
	pid = fork();
	if (pid == 0)
		last_step(fd, tmp_cmd, env, origin_env);
	close(fd[1]);
	close(fd[0]);
	wait(NULL);
}