#include "../includes/minishell.h"

int	find_comand(t_cmd *cmd, t_env *envp, char **o_env)
{
	// есть ли обратный редирект в списке команд
	int fd_in = 0;
	t_cmd *tmp = cmd;

	if (ft_strncmp_notregistr("<", tmp->cmd, ft_strlen(tmp->cmd)) && find_revers_redirect(tmp))
	{
		printf("change fd_input begin\n");
		fd_in = find_infile_des(tmp);
		if (!ft_strncmp_notregistr(">", cmd->next->cmd, ft_strlen(cmd->next->cmd)) ||
		!ft_strncmp_notregistr(">>", cmd->next->cmd, ft_strlen(cmd->next->cmd)))
			find_file_des(tmp);
		if (fd_in == -1)
			return (-1);
		dup2(fd_in, STDIN_FILENO);
	}

//------------------------------
	if (!ft_strncmp_notregistr("echo", cmd->cmd, ft_strlen(cmd->cmd)))
		//add flags in output if they not valid
		comand_echo(cmd);
	else if (!ft_strncmp_notregistr("cd", cmd->cmd, ft_strlen(cmd->cmd)))
		//+++ add tilda ~
		comand_cd(cmd, envp);
	else if (!ft_strncmp_notregistr("pwd", cmd->cmd, ft_strlen(cmd->cmd)))
		//+++
		comand_pwd(cmd, envp);
	else if (!ft_strncmp_notregistr("export", cmd->cmd, ft_strlen(cmd->cmd)))
		//+++
		comand_export(cmd, envp);
	else if (!ft_strncmp_notregistr("unset", cmd->cmd, ft_strlen(cmd->cmd)))
		//++
		comand_unset(cmd, envp);
	else if (!ft_strncmp_notregistr("env", cmd->cmd, ft_strlen(cmd->cmd)))
		//+++
		comand_env(cmd, envp);
	else if (!ft_strncmp_notregistr("exit", cmd->cmd, ft_strlen(cmd->cmd)))
		comand_exit(cmd);
	else if (!ft_strncmp_notregistr("<", cmd->cmd, ft_strlen(cmd->cmd)))
		//+++
		comand_revers_redirect(cmd);
	else if (!ft_strncmp_notregistr("<<", cmd->cmd, ft_strlen(cmd->cmd)))
		comand_revers_dredirect(cmd);
	else if (!ft_strncmp_notregistr(">", cmd->cmd, ft_strlen(cmd->cmd)) ||
		!ft_strncmp_notregistr(">>", cmd->cmd, ft_strlen(cmd->cmd)))
		//+++
		comand_redirect(cmd);
	else comand_exve(cmd, envp, o_env);
//-------------------------------------------


	if (fd_in)
		close(fd_in);


	return (0);
}


int	mainalex(t_cmd **cmd_adres, t_env **env_adres, char **origin_env)
{
	t_cmd *cmd = *cmd_adres;
	t_env *env = *env_adres;
	int	pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		find_comand(cmd, env, origin_env);
		exit (0);
	}
	wait(NULL);
	printf("%d\n", STDIN_FILENO);
	return (0);
}
