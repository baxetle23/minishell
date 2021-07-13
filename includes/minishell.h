#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <signal.h>

# define B_DARKGREY "\e[1;30m"
# define B_RED "\e[1;31m"
# define B_GREEN "\e[1;32m"
# define B_YELLOW "\e[1;33m"
# define B_BLUE "\e[1;34m"
# define B_PINK "\e[1;35m"
# define B_BLUESKY "\e[1;36m"
# define B_WHITE "\e[1;37m"

# define BLACK "\e[0;30m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define BLUE "\e[0;34m"
# define PERPLE "\e[0;35m"
# define BLUESKY "\e[0;36m"
# define GREY "\e[0;37m"

# define MANGEKENGOO "\xF0\x9F\x91\xBA:"
# define EYES "\xF0\x9F\x81\x6E:"
# define EYESES "\xF0\x9F\x91\x80:"
# define SKULL "\xF0\x9F\x92\x80:"
# define GOST "\xF0\x9F\x91\xBB:"
# define PUMPKIN "\xF0\x9F\x8E\x83:"
# define SHITS "\xF0\x9F\x92\xA9:"
# define ALIEN "\xF0\x9F\x91\xBD:"
# define ROBOT "\xF0\x9F\xA4\x96:"
# define MONKEY_EYES "\xF0\x9F\x99\x88:"
# define MONKEY_EARS "\xF0\x9F\x99\x89:"
# define MONKEY_MOUTH "\xF0\x99\x99\x8A:"
# define CHICKEN_IN_SHELL "\xF0\x99\x90\xA3:"
# define STONE_HEAD "\xF0\x9F\x97\xBF:"

# define SKULLSANDBONES "\xE2\x98\xA0"
# define INFINITY "\xE2\x99\xBE"
# define KIRPICH "\xE2\x9B\x94"

typedef struct s_words
{
	char			*word;
	int				active;
	struct s_words	*next;
	
} t_words;


typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
} t_env;

typedef struct s_cmd
{
	char			*cmd;
	char			**flags;
	char			**args;
	struct s_cmd	*next;
} t_cmd;


int		ft_checkline(char *line, t_env **env, t_cmd **cmd);

char	*ft_strdup_part(const char *s1, int start, int len);
char	*ft_strjoin_m(char *s1, char *s2);

void	ft_print_lst_words(t_words **words);
void	ft_print_lst_cmds(t_cmd **cmd);

int		ft_lst_cmd_length(t_cmd **cmd);

char	*ft_get_cmd_by_start(t_words **words, int start);
void	ft_add_all_redirects(t_words **words, int start, t_cmd **start_cmd);
int		ft_simbols_in_word(char *word);
int		ft_check_acitve(t_words **words, int start);
int		ft_count_red(t_words **words, int start);

void	ft_get_commands(t_words **words, char *line);

int		ft_simbols_in_word(char *word);
t_cmd	*ft_lstnew_cmd(char *cmd, char **flags, char **args);
void	ft_lstadd_cmd(t_cmd **lst, t_cmd *new);

void	ft_lstclear_cmds(t_cmd **env);

void	ft_add_env(t_env **lst, t_env *new);
t_env	*ft_lstnew_env(char *s);
void	ft_lstclear_env(t_env **env);
char	*ft_env_search(char *find, t_env **env);
int		ft_check_last_word(char *check, t_words **words);

int		ft_lst_words_length(t_words **words);
t_words	*ft_lstnew_word(char *s, int acitve);
void	ft_lstadd_word(t_words **lst, t_words *new);
int		ft_addword(char *word, t_words **lst, int active);
void	ft_lstclear_words(t_words **env);

void	ft_switch_spaces(int *i, char *line);
void	ft_pipe(int *i, char *line, t_words **words);

void	ft_free_mas(char **t);
void	ft_terminate(char *s);
int		ft_get_list_environments(char **e, t_env **env);

#endif