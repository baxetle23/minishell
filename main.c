#include "includes/minishell.h"

int	init_comand(t_cmd *cmd, int argc, char **argv)
{
	// name "minishell" dont add to struct
	int i = 1;
	cmd->name = ft_strdup("echo");
	
	cmd->arg = (char **)malloc(sizeof(char *) * 2);
	cmd->arg[1] = NULL;
	cmd->arg[0] =ft_strdup("");
	cmd->flags = (char **)malloc(sizeof(char *) * 3);
	cmd->flags[2] = NULL;
	cmd->flags[1] = ft_strdup("-n");
	cmd->flags[0] = ft_strdup(cmd->name);

	t_cmd	*redirect;
	redirect = (t_cmd *)malloc(sizeof(t_cmd));
	redirect->name = ft_strdup(">");
	redirect->arg = (char **)malloc(sizeof(char *) * 2); 
	redirect->arg[1] = NULL;
	redirect->arg[0] = ft_strdup("test_file1.txt");
	cmd->next = redirect;

	t_cmd *redirect2;
	redirect2 = (t_cmd *)malloc(sizeof(t_cmd));
	redirect2->name = ft_strdup(">");
	redirect2->arg = (char **)malloc(sizeof(char *) * 2); 
	redirect2->arg[1] = NULL;
	redirect2->arg[0] = ft_strdup("test_file2.txt");
	redirect->next = redirect2;
	redirect2->next = NULL;


	return (0);
}

int	find_comand(t_cmd *cmd)
{
	if (!ft_strncmp_notregistr("echo", cmd->name, ft_strlen(cmd->name)))
		comand_echo(cmd);
	if (!ft_strncmp_notregistr("cd", cmd->name, ft_strlen(cmd->name)))
		comand_cd(cmd);
	if (!ft_strncmp_notregistr("pwd", cmd->name, ft_strlen(cmd->name)))
		comand_pwd(cmd);
	if (!ft_strncmp_notregistr("export", cmd->name, ft_strlen(cmd->name)))
		comand_export(cmd);
	if (!ft_strncmp_notregistr("unset", cmd->name, ft_strlen(cmd->name)))
		comand_unset(cmd);
	if (!ft_strncmp_notregistr("env", cmd->name, ft_strlen(cmd->name)))
		comand_env(cmd);
	if (!ft_strncmp_notregistr("exit", cmd->name, ft_strlen(cmd->name)))
		comand_exit(cmd);
	if (!ft_strncmp_notregistr("<", cmd->name, ft_strlen(cmd->name)) ||
		!ft_strncmp_notregistr("<<", cmd->name, ft_strlen(cmd->name)))
		comand_redirect(cmd);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;
	
	init_comand(&cmd, argc, argv);

	// int i = 0;
	// while (cmd.flags[i])
	// 	printf("%s\n", cmd.flags[i++]);
	//printf("%s\n", cmd.name);
	
	find_comand(&cmd);
	//comand_echo(&cmd, envp);

	// printf("%s", cmd.next->arg[0]);
}
