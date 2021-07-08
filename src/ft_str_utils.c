#include "../includes/minishell.h"

char	*ft_strdup_part(const char *s1, int start, int len)
{
	int		i;
	char	*s;

	i = start;
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	while (i < len && s1[i] != '\0')
	{
		s[i - start] = s1[i];
		i++;
	}
	s[i - start] = '\0';
	return (s);
}
