#include "../includes/minishell.h"

int	ft_change_redir(t_cmd *cur, char *line, char *name)
{
	free(line);
	free(cur->cmd);
	cur->cmd = ft_strdup("<");
	free(cur->args[0]);
	cur->args[0] = name;
	return (1);
}

int	ft_create_new_file(t_cmd *cur, int i)
{
	char	*line;
	char	*name;
	char	*num;
	int		fd;

	num = ft_itoa(i);
	name = ft_strjoin(FILENAME, num);
	free(num);
	fd = open(name, O_CREAT | O_RDWR, 0777);
	line = readline("> ");
	while (line && ft_strcmp(cur->args[0], line))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline("> ");
	}
	ft_change_redir(cur, line, name);
	close(fd);
	return (0);
}
