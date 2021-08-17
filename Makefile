NAME	= minishell

SORCES	= minishell.c ft_lst_clears.c ft_lst_prints.c ft_commands_checks.c ft_commands_utils.c ft_commands.c ft_environments.c ft_str_utils.c ft_lst_utils_cmd.c ft_lst_utils_env.c ft_lst_utils_words.c ft_split_words.c ft_split_words_utils.c ft_utils.c

ALEXS = alexmain.c utils.c comands.c output.c redirect.c echo.c cd.c ft_lst_utils.c pwd.c env.c export.c execve.c unset.c revers_redirect.c pipe.c

ALEXDIRS = ./logic

DIRS	= ./parcer

DIRL	= ./libft

SRC		= $(addprefix $(DIRS)/,$(SORCES))

ALEXSRC		= $(addprefix $(ALEXDIRS)/,$(ALEXS))

OBJ		= $(SRC:.c=.o)

AOBJ		= $(ALEXSRC:.c=.o)

BOBJ	= $(BSORC:.c=.o)

HEAD	= ./includes/minishell.h

LIB		= $(DIRL)/libft.a

CC		= gcc

CFLAG	= #-Wall -Wextra -Werror

RM		= rm -f

%.o:	%.c $(HEAD)
	$(CC) $(CFLAG) -c $< -o $@

$(NAME):	$(OBJ) $(AOBJ) $(HEAD)
	$(MAKE) -C $(DIRL)
	$(CC) $(CFLAG) $(LIB) $(OBJ) $(AOBJ) -lreadline -o $(NAME)
	@echo $(NAME) is compiled!

all: $(NAME)

clean:
	$(MAKE) clean -C $(DIRL)	
	$(RM) $(OBJ) $(AOBJ) $(BOBJ)
	@echo Objects files cleaned!

fclean: clean
	$(MAKE) fclean -C $(DIRL)
	$(RM) $(NAME) $(BNAME)
	@echo All cleaned!

re: fclean all

$(BNAME):	$(BOBJ) $(HEAD)
	$(MAKE) -C $(DIRL)
	$(CC) $(CFLAG) $(LIB) $(BOBJ) -o $(BNAME)
	@echo $(BNAME) is compiled!

bonus: $(BNAME)
