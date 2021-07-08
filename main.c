#include "includes/minishell.h"

int	comand_echo(t_cmd *cmd)
{
	printf("we here\n");
	return (0);
}

int	init_comand(t_cmd *cmd, int argc, char **argv)
{
	// name "minishell" dont add to struct
	int i = 1;
	cmd->name = ft_strdup(argv[1]);
	cmd->flags = (char **)malloc(sizeof(char *) * (argc)); // + NULL
	cmd->flags[argc - 1] = NULL;
	while (argv[i])
	{
		cmd->flags[i - 1] = ft_strdup(argv[i]);
		i++;
	}
	return (0);
}

int	find_comand(t_cmd *cmd)
{
	if (!ft_strncmp_notregistr("echo", cmd->name, ft_strlen(cmd->name)))
		comand_echo(cmd);
	if (!ft_strncmp_notregistr("cd", cmd->name, ft_strlen(cmd->name)))
		comand_cd(cmd);
	if (!ft_strncmp_notregistr("cd", cmd->name, ft_strlen(cmd->name)))
		comand_cd(cmd);
	if (!ft_strncmp_notregistr("cd", cmd->name, ft_strlen(cmd->name)))
		comand_cd(cmd);
	if (!ft_strncmp_notregistr("cd", cmd->name, ft_strlen(cmd->name)))
		comand_cd(cmd);
	
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;
	
	init_comand(&cmd, argc, argv);

	// int i = 0;
	// while (cmd.flags[i])
	// 	printf("%s\n", cmd.flags[i++]);
	printf("%s\n", cmd.name);

	find_comand(&cmd);
	//comand_echo(&cmd, envp);
}
