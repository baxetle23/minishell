#include "../includes/minishell.h"

// int	init_comand(t_cmd *cmd, int argc, char **argv)
// {
// 	// name "minishell" dont add to struct
// 	//-----------------------------------------
// 	// int i = 1;
// 	// cmd->cmd = ft_strdup("echo"); // <-------------- NAME COMAND ECHO
	
// 	// cmd->arg = (char **)malloc(sizeof(char *) * 2);
// 	// cmd->arg[1] = NULL;
// 	// cmd->arg[0] =ft_strdup("test_argument"); // <------------- ARG COMAND
// 	// cmd->flags = (char **)malloc(sizeof(char *) * 3);
// 	// cmd->flags[2] = NULL;
// 	// cmd->flags[1] = ft_strdup("-N"); // <---------------- FLAG COMAND
// 	// cmd->flags[0] = ft_strdup(cmd->cmd);
// 	// //next comands
// 	// t_cmd	*redirect;
// 	// redirect = (t_cmd *)malloc(sizeof(t_cmd));
// 	// redirect->name = ft_strdup(">");
// 	// redirect->arg = (char **)malloc(sizeof(char *) * 2); 
// 	// redirect->arg[1] = NULL;
// 	// redirect->arg[0] = ft_strdup("test_file1.txt");
// 	// cmd->next = redirect;

// 	// t_cmd *redirect2;
// 	// redirect2 = (t_cmd *)malloc(sizeof(t_cmd));
// 	// redirect2->name = ft_strdup(">");
// 	// redirect2->arg = (char **)malloc(sizeof(char *) * 2); 
// 	// redirect2->arg[1] = NULL;
// 	// redirect2->arg[0] = ft_strdup("test_file3.txt");
// 	// redirect->next = redirect2;
// 	// redirect2->next = NULL;
// 	//--------------------------------------------

// 	// cmd->cmd = ft_strdup("cd"); // <-------------- NAME COMAND cd
	
// 	// cmd->arg = (char **)malloc(sizeof(char *) * 4);
// 	// cmd->arg[3] = NULL;
// 	// cmd->arg[2] = NULL;
// 	// cmd->arg[1] = NULL; // <------------- ARG COMAND
// 	// cmd->arg[0] = ft_strdup("test"); // <------------- ARG COMAND
// 	// cmd->flags = (char **)malloc(sizeof(char *) * 2);
// 	// cmd->flags[1] = NULL;
// 	// cmd->flags[0] = ft_strdup(cmd->cmd);

// 	// t_cmd	*redirect;
// 	// redirect = (t_cmd *)malloc(sizeof(t_cmd));
// 	// redirect->name = ft_strdup("-");
// 	// redirect->arg = (char **)malloc(sizeof(char *) * 2); 
// 	// redirect->arg[1] = NULL;
// 	// redirect->arg[0] = ft_strdup("test_file1.txt");
// 	// cmd->next = redirect;

// 	// t_cmd *redirect2;
// 	// redirect2 = (t_cmd *)malloc(sizeof(t_cmd));
// 	// redirect2->name = ft_strdup(">");
// 	// redirect2->arg = (char **)malloc(sizeof(char *) * 2); 
// 	// redirect2->arg[1] = NULL;
// 	// redirect2->arg[0] = ft_strdup("test_file3.txt");
// 	// redirect->next = redirect2;
// 	// redirect2->next = NULL;

// 	//--------------------------------------------

// 	// cmd->cmd = ft_strdup("pwd"); // <-------------- NAME COMAND pwd
	
// 	// cmd->arg = (char **)malloc(sizeof(char *) * 4);
// 	// cmd->arg[3] = NULL;
// 	// cmd->arg[2] = NULL;
// 	// cmd->arg[1] = NULL; // <------------- ARG COMAND
// 	// cmd->arg[0] = NULL; // <------------- ARG COMAND
// 	// cmd->flags = (char **)malloc(sizeof(char *) * 2);
// 	// cmd->flags[1] = NULL;
// 	// cmd->flags[0] = ft_strdup(cmd->cmd);

// 	// t_cmd	*redirect;
// 	// redirect = (t_cmd *)malloc(sizeof(t_cmd));
// 	// redirect->name = ft_strdup("-");
// 	// redirect->arg = (char **)malloc(sizeof(char *) * 2); 
// 	// redirect->arg[1] = NULL;
// 	// redirect->arg[0] = ft_strdup("test_file1.txt");
// 	// cmd->next = redirect;

// 	// t_cmd *redirect2;
// 	// redirect2 = (t_cmd *)malloc(sizeof(t_cmd));
// 	// redirect2->name = ft_strdup(">>");
// 	// redirect2->arg = (char **)malloc(sizeof(char *) * 2); 
// 	// redirect2->arg[1] = NULL;
// 	// redirect2->arg[0] = ft_strdup("test_file3.txt");
// 	// redirect->next = redirect2;
// 	// redirect2->next = NULL;
// 	//--------------------------------------------

// 	// cmd->cmd = ft_strdup("env"); // <-------------- NAME COMAND env
	
// 	// cmd->arg = (char **)malloc(sizeof(char *) * 4);
// 	// cmd->arg[3] = NULL;
// 	// cmd->arg[2] = NULL;
// 	// cmd->arg[1] = NULL; // <------------- ARG COMAND
// 	// cmd->arg[0] = NULL; // <------------- ARG COMAND
// 	// cmd->flags = (char **)malloc(sizeof(char *) * 2);
// 	// cmd->flags[1] = NULL;
// 	// cmd->flags[0] = ft_strdup(cmd->cmd);

// 	// t_cmd	*redirect;
// 	// redirect = (t_cmd *)malloc(sizeof(t_cmd));
// 	// redirect->name = ft_strdup(">");
// 	// redirect->arg = (char **)malloc(sizeof(char *) * 2); 
// 	// redirect->arg[1] = NULL;
// 	// redirect->arg[0] = ft_strdup("test_file1.txt");
// 	// cmd->next = redirect;

// 	// t_cmd *redirect2;
// 	// redirect2 = (t_cmd *)malloc(sizeof(t_cmd));
// 	// redirect2->name = ft_strdup(">");
// 	// redirect2->arg = (char **)malloc(sizeof(char *) * 2); 
// 	// redirect2->arg[1] = NULL;
// 	// redirect2->arg[0] = ft_strdup("test_file3.txt");
// 	// redirect->next = redirect2;
// 	// redirect2->next = NULL;

// 	//--------------------------------------------

// 	// cmd->cmd = ft_strdup("env"); // <-------------- NAME COMAND 
	
// 	// cmd->arg = (char **)malloc(sizeof(char *) * 4);
// 	// cmd->arg[3] = NULL;
// 	// cmd->arg[2] = NULL;
// 	// cmd->arg[1] = NULL; // <------------- ARG COMAND
// 	// cmd->arg[0] = NULL; // <------------- ARG COMAND
// 	// cmd->flags = (char **)malloc(sizeof(char *) * 2);
// 	// cmd->flags[1] = NULL;
// 	// cmd->flags[0] = ft_strdup(cmd->cmd);

// 	// t_cmd	*redirect;
// 	// redirect = (t_cmd *)malloc(sizeof(t_cmd));
// 	// redirect->name = ft_strdup(">");
// 	// redirect->arg = (char **)malloc(sizeof(char *) * 2); 
// 	// redirect->arg[1] = NULL;
// 	// redirect->arg[0] = ft_strdup("test_file1.txt");
// 	// cmd->next = redirect;

// 	// t_cmd *redirect2;
// 	// redirect2 = (t_cmd *)malloc(sizeof(t_cmd));
// 	// redirect2->name = ft_strdup(">");
// 	// redirect2->arg = (char **)malloc(sizeof(char *) * 2); 
// 	// redirect2->arg[1] = NULL;
// 	// redirect2->arg[0] = ft_strdup("test_file3.txt");
// 	// redirect->next = redirect2;
// 	// redirect2->next = NULL;

// 	//--------------------------------------------


// 	return (0);
// }


int	find_comand(t_cmd *cmd, t_env *envp, char **o_env)
{
	if (!ft_strncmp_notregistr("echo", cmd->cmd, ft_strlen(cmd->cmd)))
		comand_echo(cmd);
	else if (!ft_strncmp_notregistr("cd", cmd->cmd, ft_strlen(cmd->cmd)))
		comand_cd(cmd, envp);
	else if (!ft_strncmp_notregistr("pwd", cmd->cmd, ft_strlen(cmd->cmd)))
		comand_pwd(cmd, envp);
	else if (!ft_strncmp_notregistr("export", cmd->cmd, ft_strlen(cmd->cmd)))
		comand_export(cmd, envp);
	else if (!ft_strncmp_notregistr("unset", cmd->cmd, ft_strlen(cmd->cmd)))
		comand_unset(cmd);
	else if (!ft_strncmp_notregistr("env", cmd->cmd, ft_strlen(cmd->cmd)))
		comand_env(cmd, envp);
	else if (!ft_strncmp_notregistr("exit", cmd->cmd, ft_strlen(cmd->cmd)))
		comand_exit(cmd);
	else if (!ft_strncmp_notregistr("<", cmd->cmd, ft_strlen(cmd->cmd)) ||
		!ft_strncmp_notregistr("<<", cmd->cmd, ft_strlen(cmd->cmd)))
		comand_redirect(cmd);
	else comand_exve(cmd, o_env);
	return (0);
}


int	mainalex(t_cmd **cmd_adres, t_env **env_adres, char **origin_env)
{

	t_cmd *cmd = *cmd_adres;
	t_env *env = *env_adres;
	// print_comand_arg(*cmd_adres);
	find_comand(cmd, env, origin_env);
	//print_envp(env);
	return (0);
}
