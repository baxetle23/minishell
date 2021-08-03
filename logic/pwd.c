#include "../includes/minishell.h"

int	comand_pwd(t_cmd *cmd, t_env *env)
{
	// если не находим PATH вызывает execve! 
	// leaks
	int i;
	t_env	*tmp;
	char	**buffer;
	char	*temp;

	tmp = ft_find_list_env("PWD", &env);
	i = 0;
	buffer = (char **)malloc(sizeof(char *) * 2);
	buffer[1] = NULL;
	buffer[0] = ft_strdup(tmp->value);
	temp = buffer[0];
	buffer[0] = ft_strjoin(temp, "\n");
	free(temp);
	output_to_fd(buffer, cmd);
	return (0);
}