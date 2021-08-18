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

int		count_pipe(t_cmd *cmd)
{
	int	i;
	i = 0;
	while(cmd)
	{
		if (!ft_strcmp(cmd->cmd, "|"))
			i++;
		cmd = cmd->next;
	}
	return (i);
}

int fd[2][2];

void	term(pid_t *pids, int n)
{
    close(fd[0][0]);
    close(fd[0][1]);
    close(fd[1][0]);
    close(fd[1][1]);
    for (int i = 1; i <= n; i++) {
        kill(pids[i], SIGKILL);
    }
    exit(1);
}

void	term1(pid_t *pids, int n)
{
    close(fd[0][0]);
    close(fd[0][1]);
    close(fd[1][0]);
    close(fd[1][1]);
    for (int i = 1; i <= n; i++) {
        kill(pids[i], SIGKILL);
    }
}

t_cmd	*get_cmd(t_cmd *cmd, int pos)
{
	int i;

	i = 1;
	while (i != pos)
	{
		if(!ft_strcmp(cmd->cmd, "|"))
			i++;
		cmd = cmd->next;
	}
	return (cmd);
}

int	logic_pipe(t_cmd *cmd, t_env *env, char **origin_env, int argc)
{
	pid_t pids[argc];
	int fd_in = 0;
	int save_stdin = dup(STDIN_FILENO);
	
	if (pipe(fd[0]) == -1) {
		exit(1);
	}
	if (pipe(fd[1]) == -1) {
		exit(1);
	}
	printf("begin %d\n", status_erorr);
	for (int i = 1; i < argc; i++) {
		pids[i] = fork();
		if (pids[i] == -1) {
			term(pids, i - 1);
		}
		if (!pids[i]) {
			close(fd[i & 1][1]);
			close(fd[1 - (i & 1)][0]);
			if (i > 1 && dup2(fd[i & 1][0], 0) == -1) {
				exit(1);
			}
			close(fd[i & 1][0]);
			if (i != argc - 1) {
				if (dup2(fd[1 - (i & 1)][1], 1) == -1)
					exit(1);
			}
			close(fd[1 - (i & 1)][1]);
			cmd = get_cmd(cmd, i);
			exit(find_comand(cmd, env, origin_env));
		}
		close(fd[i & 1][0]);
		close(fd[i & 1][1]);
		wait(&status_erorr);
		printf("status %d\n", status_erorr);
		if (status_erorr > 127)
			status_erorr = 256 - WEXITSTATUS(status_erorr);
		else 
			status_erorr = WEXITSTATUS(status_erorr);
		printf("%d %d\n", i, status_erorr);
		
		if (i == argc - 1) {
			close(fd[0][0]);
			close(fd[0][1]);
			close(fd[1][0]);
			close(fd[1][1]);
		}
		if (pipe(fd[i & 1]) == -1) {
			term1(pids, i);
		}	
	}
	
	//waitpid(pids[argc - 1], &status_erorr, 0);
	dup2(save_stdin, 0);
	return 0;
}