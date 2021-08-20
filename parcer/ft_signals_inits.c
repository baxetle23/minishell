#include "../includes/minishell.h"

void	ft_siginit(void)
{
	signal(SIGINT, ft_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_siginit_cat(void)
{
	signal(SIGINT, ft_ctrl_c_cat);
	signal(SIGQUIT, ft_ctrl_bs_cat);
}
