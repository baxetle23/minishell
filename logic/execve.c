#include "../includes/minishell.h"

int	comand_exve(t_cmd *cmd, t_env *envp)
{
	// найти fd
	// use dup2
	// find path comand
	// use execve

	t_cmd *redirect;
	int	fd;

	fd = find_file_des(cmd);
	dup2(fd, STDIN_FILENO);
	close(fd);


	
}