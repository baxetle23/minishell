#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_cmd
{
	char	*name;
	char	**flags;
	char	**arg;
	struct	s_cmd *next;
}			t_cmd;


int	ft_strncmp_notregistr(const char *s1, const char *s2, size_t n);