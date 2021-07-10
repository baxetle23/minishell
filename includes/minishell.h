#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct s_cmd
{
	char			*name;
	char			**flags;
	char			**arg;
	struct	s_cmd	*next;
}					t_cmd;

typedef struct  s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

int	ft_strncmp_notregistr(const char *s1, const char *s2, size_t n);

int	comand_echo(t_cmd *cmd);
int	comand_cd(t_cmd *cmd, t_env *envp);
int	comand_pwd(t_cmd *cmd, t_env *envp);
int	comand_export(t_cmd *cmd);
int	comand_unset(t_cmd *cmd);
int	comand_env(t_cmd *cmd);
int	comand_exit(t_cmd *cmd);
int	comand_redirect(t_cmd *cmd);

t_cmd	*find_redirect(t_cmd *cmd);
t_cmd	*many_redirect(t_cmd *cmd);

//--------------------------------------------------------
int		ft_get_list_environments(char **e, t_env **env);
t_env	*ft_get_list_env(char *find, t_env **env);
char	*ft_env_search(char *find, t_env **env);
void	print_envp(t_env *envp);
t_env	*find_list_envp(const char * key, t_env *envp);