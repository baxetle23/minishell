#include "../includes/minishell.h"

int	search_name_comand(t_cmd *cmd, t_env *envp, char **o_env)
{
	if (!ft_strncmp_notregistr("echo", cmd->cmd, ft_strlen(cmd->cmd)))
		g_status_erorr = comand_echo(cmd);
	else if (!ft_strncmp_notregistr("cd", cmd->cmd, ft_strlen(cmd->cmd)))
		g_status_erorr = comand_cd(cmd, envp);
	else if (!ft_strncmp_notregistr("pwd", cmd->cmd, ft_strlen(cmd->cmd)))
		g_status_erorr = comand_pwd(cmd, envp, o_env);
	else if (!ft_strncmp_notregistr("export", cmd->cmd, ft_strlen(cmd->cmd)))
		g_status_erorr = comand_export(cmd, envp);
	else if (!ft_strncmp_notregistr("unset", cmd->cmd, ft_strlen(cmd->cmd)))
		g_status_erorr = comand_unset(cmd, envp);
	else if (!ft_strncmp_notregistr("env", cmd->cmd, ft_strlen(cmd->cmd)))
		g_status_erorr = comand_env(cmd, envp);
	else if (!ft_strncmp_notregistr("exit", cmd->cmd, ft_strlen(cmd->cmd)))
		g_status_erorr = comand_exit(cmd);
	else if (!ft_strncmp_notregistr("<", cmd->cmd,
			ft_strlen(cmd->cmd)) && cmd->active)
		g_status_erorr = comand_revers_redirect(cmd);
	else if ((!ft_strncmp_notregistr(">", cmd->cmd,
				ft_strlen(cmd->cmd))
			|| !ft_strncmp_notregistr(">>", cmd->cmd,
				ft_strlen(cmd->cmd))) && cmd->active)
		g_status_erorr = comand_redirect(cmd);
	else
		g_status_erorr = comand_exve(cmd, envp, o_env);
	return (g_status_erorr);
}

void	init_infile_des(int *fd_in, int *save_in)
{
	*fd_in = 0;
	*save_in = dup(STDIN_FILENO);
}

int	find_comand(t_cmd *cmd, t_env *envp, char **o_env)
{
	int		fd_in;
	t_cmd	*tmp;
	int		save_stdin;

	init_infile_des(&fd_in, &save_stdin);
	tmp = cmd;
	if (ft_strncmp_notregistr("<", tmp->cmd,
			ft_strlen(tmp->cmd)) && find_revers_redirect(tmp))
	{
		fd_in = find_infile_des(tmp);
		if (!ft_strncmp_notregistr(">", cmd->next->cmd,
				ft_strlen(cmd->next->cmd)) || !ft_strncmp_notregistr(">>",
				cmd->next->cmd, ft_strlen(cmd->next->cmd)))
			find_file_des(tmp);
		if (fd_in == -1)
			return (g_status_erorr = 1);
		dup2(fd_in, STDIN_FILENO);
	}
	search_name_comand(cmd, envp, o_env);
	if (fd_in)
	{
		close(fd_in);
		dup2(save_stdin, 0);
	}
	return (g_status_erorr);
}

int	mainalex(t_cmd **cmd_adres, t_env **env_adres, char **origin_env)
{
	t_cmd	*cmd;
	t_env	*env;

	cmd = *cmd_adres;
	env = *env_adres;
	g_status_erorr = 0;
	if (pipe_exist(cmd))
		logic_pipe(cmd, env, origin_env, count_pipe(cmd) + 2);
	else
		find_comand(cmd, env, origin_env);
	return (0);
}
