#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct s_cmd
{
	char	*name;
	char	**flags;
	char	**arg;
	struct	s_cmd *next;
}			t_cmd;


int	ft_strncmp_notregistr(const char *s1, const char *s2, size_t n);

int	comand_echo(t_cmd *cmd);
int	comand_cd(t_cmd *cmd);
int	comand_pwd(t_cmd *cmd);
int	comand_export(t_cmd *cmd);
int	comand_unset(t_cmd *cmd);
int	comand_env(t_cmd *cmd);
int	comand_exit(t_cmd *cmd);
int	comand_redirect(t_cmd *cmd);

t_cmd	*find_redirect(t_cmd *cmd);
t_cmd	*many_redirect(t_cmd *cmd);