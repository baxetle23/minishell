#include "../includes/minishell.h"

int	ft_print_syntaxerror(void)
{
	write(1, "!\xF0\x9F\x91\x80!: syntax error\n", 21);
	return (0);
}
