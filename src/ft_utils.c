#include "../includes/minishell.h"

void	ft_terminate(char *s)
{
	ft_putstr_fd(s, 2);
	exit (1);
}

int	ft_put_caption(void)
{
	int	*smile;

	smile = (int*)malloc(sizeof(int) * 4);
/*	smile[0] = 240;
	smile[1] = 159;
	smile[2] = 148;
	smile[3] = 158;
*/
	smile[0] = 240;
	smile[1] = 159;
	smile[2] = 145;
	smile[3] = 186;
	write(1, B_RED, 8);
	write(1, "minishell", 9);
	ft_putchar_fd(smile[0], 1);
//	write(1, " ", 1);
	ft_putchar_fd(smile[1], 1);
//	write(1, " ", 1);
	ft_putchar_fd(smile[2], 1);
//	write(1, " ", 1);
	ft_putchar_fd(smile[3], 1);
	free(smile);
	write(1, ":", 1);
	write(1, GREY, 8);
	return (0);
}
