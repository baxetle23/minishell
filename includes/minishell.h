#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <sys/wait.h>

# define B_DARKGREY "\e[1;30m"
# define B_RED "\e[1;31m"
# define B_GREEN "\e[1;32m"
# define B_YELLOW "\e[1;33m"
# define B_BLUE "\e[1;34m"
# define B_PINK "\e[1;35m"
# define B_BLUESKY "\e[1;36m"
# define B_WHITE "\e[1;37m"

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

# define MANGEKENGOO "\xF0\x9F\x91\xBA:"
# define EYES "\xF0\x9F\x81\x6E:"
# define EYESES "<:\xF0\x9F\x91\x80:> "
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

# define FILENAME "./.tmp/1time194fir_"

typedef struct s_words
{
	char			*word;
	int				active;
	struct s_words	*next;

}	t_words;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_cmd
{
	char			*cmd;
	int				active;
	char			**flags;
	char			**args;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pipex
{
	char	*addres;
	char	*addres_full;
	char	**strings_way;
	char	**comand;
	int		i;
}			t_pipex;

int		g_status_error;

//readline
char	*readline(const char *line);
int		add_history(const char *line);
int		rl_on_new_line(void);
void	dl_redisplay(void);
void	rl_replace_line(const char *buffer, int val);

//signals

void	ft_siginit(void);

void	ft_add_all_redirects(t_words **words, int start, t_cmd **start_cmd);
int		ft_count_red(t_words **words, int start);
void	ft_change_double_red(t_cmd **cmd);

int		ft_create_new_file(t_cmd *cur, int i);
int		ft_comm_check(t_cmd **cmd);
void	ft_echo_fill(t_cmd *cmd);

int		ft_checkline(char *line, t_env **env, t_cmd **cmd, char **envir);
int		ft_check_redir(t_cmd *tmp);
int		ft_check_pipe(t_cmd *tmp);

char	*ft_strdup_part(const char *s1, int start, int len);
char	*ft_strjoin_m(char *s1, char *s2);
void	ft_switch_spaces(int *i, char *line);
int		ft_spec_char(char c);

void	ft_print_lst_words(t_words **words);
void	ft_print_lst_cmds(t_cmd **cmd);

int		ft_lst_cmd_length(t_cmd **cmd);

t_words	*ft_skip_redir(t_words **words, int *i);
t_words	*ft_skip_redir_i_flags(t_words **words, int i, int flags_c);
int		ft_get_count_flags(t_words **words, int	i);
int		ft_get_count_args(t_words **words, int	i, int flags_c);

char	*ft_get_cmd_by_start(t_words **words, int start);
void	ft_add_all_redirects(t_words **words, int start, t_cmd **start_cmd);
int		ft_simbols_in_word(char *word);
int		ft_check_acitve(t_words **words, int start);
int		ft_count_red(t_words **words, int start);

void	ft_get_comm(t_words **words, t_cmd **cmd, int start, int old_start);

int		ft_simbols_in_word(char *word);
t_cmd	*ft_lstnew_cmd(char *cmd, char **flags, char **args, int active);
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

int		ft_print_syntaxerror(void);

void	ft_pipe(int *i, char *line, t_words **words);
char	*ft_dollar(int *i, char *line, t_env **env);
char	*ft_char(int *i, char *line, t_env **env);
char	*ft_upostr(int *i, char *line);
char	*ft_kavichki(int *i, char *line, t_env **env);

char	**get_empty_m(void);
void	ft_free_mas(char **t);
void	ft_terminate(char *s);
void	ft_remove_files(t_cmd **cmd);
void	ft_clear_all(t_words **words, t_cmd **cmd, char *line, char *res_word);

int		ft_is_redirect(t_words *tmp);
int		ft_is_pipe(t_words *tmp);

int		ft_get_list_environments(char **e, t_env **env);
t_env	*ft_find_list_env(char *find, t_env **env);

void	ft_siginit_cat(void);

//--------------------------------------------------------
int		mainalex(t_cmd **cmd_adres, t_env **env, char **origin);

int		ft_strncmp_nr(const char *s1, const char *s2, size_t n);

int		find_comand(t_cmd *cmd, t_env *envp, char **o_env);
int		comand_echo(t_cmd *cmd);
int		comand_cd(t_cmd *cmd, t_env *envp);
int		comand_pwd(t_cmd *cmd, t_env *envp, char **o_env);
int		comand_export(t_cmd *cmd, t_env *envp);
int		comand_unset(t_cmd *cmd, t_env *envp);
int		comand_env(t_cmd *cmd, t_env *envp);
int		comand_exit(t_cmd *cmd);
int		comand_redirect(t_cmd *cmd);
int		comand_revers_redirect(t_cmd *cmd);
int		comand_revers_dredirect(t_cmd *cmd);
int		comand_exve(t_cmd *cmd, t_env *envp, char **o_env);

void	call_execve_process(t_cmd *cmd, t_env *envp, char **o_env);
void	check_minishell(char *name, char **o_env, t_cmd *cmd);
int		check_path(t_cmd *cmd, t_env *envp);
int		absolute_path(char *name_programm);
void	free_memory(char **split1, char **split2);

int		sort_env(t_env *env);
void	print_sort_envp(t_env *envp, int fd);

void	free_function(char *key, char *value, t_env *env);
void	free_memory(char **split1, char **split2);
void	change_value(t_env *new, char *key, t_env *env, char *value);

//redirect
int		output_to_fd(char **buffer, t_cmd *cmd);
t_cmd	*find_redirect(t_cmd *cmd);
int		find_file_des(t_cmd *cmd);
int		print_mistake(char *file);
//revers redirect
t_cmd	*find_revers_redirect(t_cmd *cmd);
int		find_infile_des(t_cmd *cmd);
//pipe
t_cmd	*pipe_exist(t_cmd *cmd);
int		count_pipe(t_cmd *cmd);
int		logic_pipe(t_cmd *cmd, t_env *env, char **origin_env, int argc);
void	term(pid_t *pids, int n, int g_fd[2][2]);
void	term1(pid_t *pids, int n, int g_fd[2][2]);
t_cmd	*get_cmd(t_cmd *cmd, int pos);
void	init_for_pipe(int *i, pid_t **pids, int *save, int argc);

//--------------------------------------------------------

void	print_envp(t_env *envp, int fd);
void	print_comand_arg(t_cmd *cmd);
void	print_sort_envp(t_env *envp, int fd);

void	ft_delete_list_env(char *key, t_env **env);
#endif
