NAME 			= minishell

HEADER			= ./includes/minishell.h

SRCS			=	main.c utils.c comands.c find.c

OBJS			= $(SRCS:.c=.o)
%.o:			%.c ${HEADER}
				$(CC) $(CFLAGS) -c -o $@ $<

RM				= rm -f
CFLAGS			= #-Wall -Werror -Wextra
INCLUDES		= ./includes/minishell.h

$(NAME):		$(OBJS) $(HEADER)
				$(MAKE) -C ./libft
				cp libft/libft.a ./$(NAME)
				gcc $(OBJS) ./libft/libft.a -o ${NAME}

all:			$(NAME)
clean:
				$(MAKE) clean -C ./libft	
				$(RM) $(OBJS)		

fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)
				
re:				fclean all
test:			all
.PHONY:			all clean fclean re
