#include "includes/minishell.h"

int	init_comand(t_cmd *cmd, int argc, char **argv)
{
	// name "minishell" dont add to struct
	//-----------------------------------------
	// int i = 1;
	// cmd->name = ft_strdup("echo"); // <-------------- NAME COMAND ECHO
	
	// cmd->arg = (char **)malloc(sizeof(char *) * 2);
	// cmd->arg[1] = NULL;
	// cmd->arg[0] =ft_strdup("test_argument"); // <------------- ARG COMAND
	// cmd->flags = (char **)malloc(sizeof(char *) * 3);
	// cmd->flags[2] = NULL;
	// cmd->flags[1] = ft_strdup("-N"); // <---------------- FLAG COMAND
	// cmd->flags[0] = ft_strdup(cmd->name);
	// //next comands
	// t_cmd	*redirect;
	// redirect = (t_cmd *)malloc(sizeof(t_cmd));
	// redirect->name = ft_strdup(">");
	// redirect->arg = (char **)malloc(sizeof(char *) * 2); 
	// redirect->arg[1] = NULL;
	// redirect->arg[0] = ft_strdup("test_file1.txt");
	// cmd->next = redirect;

	// t_cmd *redirect2;
	// redirect2 = (t_cmd *)malloc(sizeof(t_cmd));
	// redirect2->name = ft_strdup(">");
	// redirect2->arg = (char **)malloc(sizeof(char *) * 2); 
	// redirect2->arg[1] = NULL;
	// redirect2->arg[0] = ft_strdup("test_file3.txt");
	// redirect->next = redirect2;
	// redirect2->next = NULL;
	//--------------------------------------------

	// cmd->name = ft_strdup("cd"); // <-------------- NAME COMAND cd
	
	// cmd->arg = (char **)malloc(sizeof(char *) * 4);
	// cmd->arg[3] = NULL;
	// cmd->arg[2] = NULL;
	// cmd->arg[1] = NULL; // <------------- ARG COMAND
	// cmd->arg[0] = ft_strdup("test"); // <------------- ARG COMAND
	// cmd->flags = (char **)malloc(sizeof(char *) * 2);
	// cmd->flags[1] = NULL;
	// cmd->flags[0] = ft_strdup(cmd->name);

	// t_cmd	*redirect;
	// redirect = (t_cmd *)malloc(sizeof(t_cmd));
	// redirect->name = ft_strdup("-");
	// redirect->arg = (char **)malloc(sizeof(char *) * 2); 
	// redirect->arg[1] = NULL;
	// redirect->arg[0] = ft_strdup("test_file1.txt");
	// cmd->next = redirect;

	// t_cmd *redirect2;
	// redirect2 = (t_cmd *)malloc(sizeof(t_cmd));
	// redirect2->name = ft_strdup(">");
	// redirect2->arg = (char **)malloc(sizeof(char *) * 2); 
	// redirect2->arg[1] = NULL;
	// redirect2->arg[0] = ft_strdup("test_file3.txt");
	// redirect->next = redirect2;
	// redirect2->next = NULL;

	//--------------------------------------------

	// cmd->name = ft_strdup("pwd"); // <-------------- NAME COMAND pwd
	
	// cmd->arg = (char **)malloc(sizeof(char *) * 4);
	// cmd->arg[3] = NULL;
	// cmd->arg[2] = NULL;
	// cmd->arg[1] = NULL; // <------------- ARG COMAND
	// cmd->arg[0] = NULL; // <------------- ARG COMAND
	// cmd->flags = (char **)malloc(sizeof(char *) * 2);
	// cmd->flags[1] = NULL;
	// cmd->flags[0] = ft_strdup(cmd->name);

	// t_cmd	*redirect;
	// redirect = (t_cmd *)malloc(sizeof(t_cmd));
	// redirect->name = ft_strdup("-");
	// redirect->arg = (char **)malloc(sizeof(char *) * 2); 
	// redirect->arg[1] = NULL;
	// redirect->arg[0] = ft_strdup("test_file1.txt");
	// cmd->next = redirect;

	// t_cmd *redirect2;
	// redirect2 = (t_cmd *)malloc(sizeof(t_cmd));
	// redirect2->name = ft_strdup(">>");
	// redirect2->arg = (char **)malloc(sizeof(char *) * 2); 
	// redirect2->arg[1] = NULL;
	// redirect2->arg[0] = ft_strdup("test_file3.txt");
	// redirect->next = redirect2;
	// redirect2->next = NULL;
	//--------------------------------------------

	// cmd->name = ft_strdup("env"); // <-------------- NAME COMAND env
	
	// cmd->arg = (char **)malloc(sizeof(char *) * 4);
	// cmd->arg[3] = NULL;
	// cmd->arg[2] = NULL;
	// cmd->arg[1] = NULL; // <------------- ARG COMAND
	// cmd->arg[0] = NULL; // <------------- ARG COMAND
	// cmd->flags = (char **)malloc(sizeof(char *) * 2);
	// cmd->flags[1] = NULL;
	// cmd->flags[0] = ft_strdup(cmd->name);

	// t_cmd	*redirect;
	// redirect = (t_cmd *)malloc(sizeof(t_cmd));
	// redirect->name = ft_strdup(">");
	// redirect->arg = (char **)malloc(sizeof(char *) * 2); 
	// redirect->arg[1] = NULL;
	// redirect->arg[0] = ft_strdup("test_file1.txt");
	// cmd->next = redirect;

	// t_cmd *redirect2;
	// redirect2 = (t_cmd *)malloc(sizeof(t_cmd));
	// redirect2->name = ft_strdup(">");
	// redirect2->arg = (char **)malloc(sizeof(char *) * 2); 
	// redirect2->arg[1] = NULL;
	// redirect2->arg[0] = ft_strdup("test_file3.txt");
	// redirect->next = redirect2;
	// redirect2->next = NULL;

	//--------------------------------------------

	cmd->name = ft_strdup("env"); // <-------------- NAME COMAND 
	
	cmd->arg = (char **)malloc(sizeof(char *) * 4);
	cmd->arg[3] = NULL;
	cmd->arg[2] = NULL;
	cmd->arg[1] = NULL; // <------------- ARG COMAND
	cmd->arg[0] = NULL; // <------------- ARG COMAND
	cmd->flags = (char **)malloc(sizeof(char *) * 2);
	cmd->flags[1] = NULL;
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
	redirect2->arg[0] = ft_strdup("test_file3.txt");
	redirect->next = redirect2;
	// redirect2->next = NULL;

	//--------------------------------------------


	return (0);
}


int	find_comand(t_cmd *cmd, t_env *envp)
{
	if (!ft_strncmp_notregistr("echo", cmd->name, ft_strlen(cmd->name)))
		comand_echo(cmd);
	if (!ft_strncmp_notregistr("cd", cmd->name, ft_strlen(cmd->name)))
		comand_cd(cmd, envp);
	if (!ft_strncmp_notregistr("pwd", cmd->name, ft_strlen(cmd->name)))
		comand_pwd(cmd, envp);
	if (!ft_strncmp_notregistr("export", cmd->name, ft_strlen(cmd->name)))
		comand_export(cmd, envp);
	if (!ft_strncmp_notregistr("unset", cmd->name, ft_strlen(cmd->name)))
		comand_unset(cmd);
	if (!ft_strncmp_notregistr("env", cmd->name, ft_strlen(cmd->name)))
		comand_env(cmd, envp);
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
	t_env	*env = NULL;
	init_comand(&cmd, argc, argv); // <------- SEREGA DELAET
	ft_get_list_environments(envp, &env); // <------- SEREGA DELAET	

	 //print_envp(env);
	find_comand(&cmd, env);
	//print_envp(env);
}
