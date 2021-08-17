#include "../includes/minishell.h"

int	comand_pwd(t_cmd *cmd, t_env *env, char **env_o)
{
	int i;
	t_env	*tmp;
	char	**buffer;
	char	*temp;

	tmp = ft_find_list_env("PWD", &env);
	if (tmp == NULL)
		return (comand_exve(cmd, env, env_o));
	i = 0;
	buffer = (char **)malloc(sizeof(char *) * 2);
	buffer[1] = NULL;
	buffer[0] = ft_strdup(tmp->value);
	temp = buffer[0];
	buffer[0] = ft_strjoin(temp, "\n");
	free(temp);
	return (output_to_fd(buffer, cmd));
}