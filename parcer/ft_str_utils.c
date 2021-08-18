#include "../includes/minishell.h"

char	*ft_strdup_part(const char *s1, int start, int len)
{
	int		i;
	char	*s;

	i = start;
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	while (i < len + start && s1[i] != '\0')
	{
		s[i - start] = s1[i];
		i++;
	}
	s[i - start] = '\0';
	return (s);
}

void	ft_str_fill(char *s1, char *s2, char *res, int *i)
{
	int	j;

	*i = 0;
	while (s1[*i] != '\0')
	{
		res[*i] = s1[*i];
		*i = *i + 1;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		res[*i] = s2[j++];
		*i = *i + 1;
	}
}

char	*ft_strjoin_m(char *s1, char *s2)
{
	int		i;
	char	*res;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	else if (s1 == NULL)
		return (s2);
	else if (s2 == NULL)
		return (s1);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (0);
	ft_str_fill(s1, s2, res, &i);
	free(s1);
	free(s2);
	res[i] = '\0';
	return (res);
}
