#include "../includes/minishell.h"

char *ft_lineclear(char *line, t_env **env)
{

}

int	ft_checkline(char *line, t_env **env)
{
	char *clear_line;

	clear_line = ft_lineclear(line);

	printf("%s\n", clear_line);
}