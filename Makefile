NAME	= minishell

SORCES	=	ft_comm_redirect_utils.c \
			ft_commands_checks.c \
			ft_commands_utils_2.c \
			ft_commands_utils.c \
			ft_commands.c \
			ft_environments.c \
			ft_files.c \
			ft_lst_clears.c \
			ft_lst_prints.c \
			ft_lst_utils_cmd.c \
			ft_lst_utils_env.c \
			ft_lst_utils_words.c \
			ft_other_prints.c \
			ft_signals_inits.c \
			ft_signals.c \
			ft_split_words_utils.c \
			ft_split_words.c \
			ft_str_utils.c \
			ft_utils_other.c \
			ft_utils.c \
			minishell.c

ALEXS = alexmain.c\
		utils.c\
		comands.c\
		output.c\
		redirect.c\
		echo.c\
		cd.c\
		ft_lst_utils.c\
		pwd.c\
		env.c\
		export.c\
		execve.c\
		unset.c\
		revers_redirect.c\
		pipe.c\
		execve_2.c\
		export_2.c\
		pipe_logic.c\
		exit.c

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

CFLAG	= -Wall -Wextra -Werror

RM		= rm -f

%.o:	%.c $(HEAD)
	$(CC) $(CFLAG) -c $< -o $@

$(NAME):	$(OBJ) $(AOBJ) $(HEAD)
	$(MAKE) -C $(DIRL)
	$(CC) $(CFLAG) $(LIB) $(OBJ) $(AOBJ) -lreadline -ltermcap -g -L/Users/$(USER)/.brew/Cellar/readline/8.1/lib/ -I/Users/$(USER)/.brew/Cellar/readline/8.1/include -o $(NAME)
	@echo '\033[4;1m' $(NAME) '\033[0;1m' is compiled! '\033[0m''\xF0\x9F\x91\x80'

all: $(NAME)

clean:
	$(MAKE) clean -C $(DIRL)	
	$(RM) $(OBJ) $(AOBJ) $(BOBJ)
	@echo '\033[1m' Objects files cleaned! '\033[0m'

fclean: clean
	$(MAKE) fclean -C $(DIRL)
	$(RM) $(NAME) $(BNAME)
	@echo '\033[1m' All cleaned! '\033[0m'

re: fclean all

$(BNAME):	$(BOBJ) $(HEAD)
	$(MAKE) -C $(DIRL)
	$(CC) $(CFLAG) $(LIB) $(BOBJ) -o $(BNAME)
	@echo '\033[1m' $(BNAME) is compiled! '\033[0m'

bonus: $(BNAME)
