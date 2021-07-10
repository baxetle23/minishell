NAME	= minishell

SORCES	= minishell.c ft_checks.c ft_environments.c ft_str_utils.c ft_lst_utils.c ft_utils.c

DIRS	= ./src

DIRL	= ./libft

SRC		= $(addprefix $(DIRS)/,$(SORCES))

OBJ		= $(SRC:.c=.o)

BOBJ	= $(BSORC:.c=.o)

HEAD	= includes/minishell.h

LIB		= $(DIRL)/libft.a

CC		= gcc

CFLAG	= -Wall -Wextra -Werror

RM		= rm -f

%.o:	%.c $(HEAD)
	$(CC) $(CFLAG) -c $< -o $@

$(NAME):	$(OBJ) $(HEAD)
	$(MAKE) -C $(DIRL)
	$(CC) $(CFLAG) $(LIB) $(OBJ) -lreadline -o $(NAME)
	@echo $(NAME) is compiled!

all: $(NAME)

clean:
	$(MAKE) clean -C $(DIRL)	
	$(RM) $(OBJ) $(BOBJ)
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

