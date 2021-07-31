#include "../includes/minishell.h"

int	find_comand(t_cmd *cmd, t_env *envp, char **o_env)
{
	// есть ли обратный редирект в списке команд
	if (ft_strncmp_notregistr("<", cmd->cmd, ft_strlen(cmd->cmd)) && find_revers_redirect(cmd))
	{
		printf("change fd begin\n");
		int fd_in;
	// подменить stdin для дальнейших команд в случае ошибки прекратить выполнение этих команд
		fd_in = find_infile_des(cmd);
		if (fd_in == -1)
			return (-1);
		printf("%d fd\n", fd_in);
		write(fd_in, "test fd\n", 8);
	}


	if (!ft_strncmp_notregistr("echo", cmd->cmd, ft_strlen(cmd->cmd)))
		//add flags in output if they not valid
		comand_echo(cmd);
	else if (!ft_strncmp_notregistr("cd", cmd->cmd, ft_strlen(cmd->cmd)))
		//+++
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
		comand_revers_redirect(cmd);
	else if (!ft_strncmp_notregistr("<<", cmd->cmd, ft_strlen(cmd->cmd)))
		comand_revers_dredirect(cmd);
	else if (!ft_strncmp_notregistr(">", cmd->cmd, ft_strlen(cmd->cmd)) ||
		!ft_strncmp_notregistr(">>", cmd->cmd, ft_strlen(cmd->cmd)))
		comand_redirect(cmd);
	else comand_exve(cmd, envp, o_env);
	return (0);
}


int	mainalex(t_cmd **cmd_adres, t_env **env_adres, char **origin_env)
{
	t_cmd *cmd = *cmd_adres;
	t_env *env = *env_adres;
	find_comand(cmd, env, origin_env);
	return (0);
}
