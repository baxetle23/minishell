#include "../includes/minishell.h"

void	ft_ctrl_c(int id)
{
	if (id == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(1, "  \n", 3);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_ctrl_c_cat(int id)
{
	(void) id;
	write (1, "\n", 1);
	g_status_error = 130;
}

void	ft_ctrl_d(int id)
{
	(void) id;
	exit(g_status_error);
}

void	ft_ctrl_bs_cat(int id)
{
	(void) id;
	write(1, "Quit: 3\n", 8);
	g_status_error = 131;
}
