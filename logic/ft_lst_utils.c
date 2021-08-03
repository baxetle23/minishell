#include "../includes/minishell.h"

void print_comand_arg(t_cmd *cmd)
{
	int i = 0;
	printf(GREEN "name: %s\n" RESET, cmd->cmd);
	if (cmd->args)
	{
		printf(GREEN "arg: " RESET);
		while (cmd->args[i]) {
			printf(GREEN " %s" RESET, cmd->args[i]);
			i++;
		}
		printf("\n");
	}
		
}

void print_envp(t_env *envp, int fd)
{
	t_env *tmp = envp;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, fd);
			write(fd, "=", 1);
			ft_putendl_fd(tmp->value, fd);
		}
		tmp = tmp->next;
	}
}

t_env *find_list_envp(const char * key, t_env *envp)
{
	t_env *tmp;
	tmp = envp;
	while (tmp)
	{
		if (!ft_strncmp(key, tmp->key, ft_strlen(key) && ft_strlen(key) == ft_strlen(tmp->key)))
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}