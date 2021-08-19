#include "../includes/minishell.h"

int	search_name_comand(t_cmd *cmd, t_env *envp, char **o_env)
{
	if (!ft_strncmp_nr("echo", cmd->cmd, 4))
		g_status_error = comand_echo(cmd);
	else if (!ft_strncmp_nr("cd", cmd->cmd, 2))
		g_status_error = comand_cd(cmd, envp);
	else if (!ft_strncmp_nr("pwd", cmd->cmd, 3))
		g_status_error = comand_pwd(cmd, envp, o_env);
	else if (!ft_strncmp_nr("export", cmd->cmd, 6))
		g_status_error = comand_export(cmd, envp);
	else if (!ft_strncmp_nr("unset", cmd->cmd, 5))
		g_status_error = comand_unset(cmd, envp);
	else if (!ft_strncmp_nr("env", cmd->cmd, 3))
		g_status_error = comand_env(cmd, envp);
	else if (!ft_strncmp_nr("exit", cmd->cmd, 4))
		g_status_error = comand_exit(cmd);
	else if (!ft_strncmp_nr("<", cmd->cmd,
			1) && cmd->active)
		g_status_error = comand_revers_redirect(cmd);
	else if ((!ft_strncmp_nr(">", cmd->cmd,
				1)
			|| !ft_strncmp_nr(">>", cmd->cmd,
				2)) && cmd->active)
		g_status_error = comand_redirect(cmd);
	else
		g_status_error = comand_exve(cmd, envp, o_env);
	return (g_status_error);
}

void	init_infile_des(int *fd_in, int *save_in, t_cmd *cmd)
{
	if (ft_strncmp_nr("exit", cmd->cmd, 4))
		g_status_error = 0;
	*fd_in = 0;
	*save_in = dup(STDIN_FILENO);
}

int	find_comand(t_cmd *cmd, t_env *envp, char **o_env)
{
	int		fd_in;
	t_cmd	*tmp;
	int		save_stdin;

	init_infile_des(&fd_in, &save_stdin, cmd);
	tmp = cmd;
	if (ft_strncmp_nr("<", tmp->cmd,
			ft_strlen(tmp->cmd)) && find_revers_redirect(tmp))
	{
		fd_in = find_infile_des(tmp);
		if (!ft_strncmp_nr(">", cmd->next->cmd,
				ft_strlen(cmd->next->cmd)) || !ft_strncmp_nr(">>",
				cmd->next->cmd, ft_strlen(cmd->next->cmd)))
			find_file_des(tmp);
		if (fd_in == -1)
			return (g_status_error = 1);
		dup2(fd_in, STDIN_FILENO);
	}
	search_name_comand(cmd, envp, o_env);
	if (fd_in)
	{
		close(fd_in);
		dup2(save_stdin, 0);
	}
	return (g_status_error);
}

int	mainalex(t_cmd **cmd_adres, t_env **env_adres, char **origin_env)
{
	t_cmd	*cmd;
	t_env	*env;

	cmd = *cmd_adres;
	env = *env_adres;
	if (pipe_exist(cmd))
		logic_pipe(cmd, env, origin_env, count_pipe(cmd) + 2);
	else
		find_comand(cmd, env, origin_env);
	return (0);
}
