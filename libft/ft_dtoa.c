#include "libft.h"

static int	ft_get_count(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n < -9 || n > 9)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

void	ft_get_accur(char **num, double n, int *i, int ac)
{
	int	tmp;
	int	len;
	int	j;

	len = *i;
	if (n < 0)
		n = (double)n * -1;
	num[0][*i] = '.';
	while (*i < len + ac)
	{
		tmp = (int)n;
		n = (double)n - tmp;
		j = 0;
		while (j++ < 7 && (*i)++ < len + ac)
		{
			n = (double)n * 10;
			num[0][*i] = (int)n % 10 + '0';
		}
	}
}

char	*ft_dtoa(double n, int ac)
{
	char	*num;
	char	*ch;
	int		count;
	int		i;
	int		j;

	count = ft_get_count(n);
	num = (char *)malloc(sizeof(char) * (count + ac + 2));
	if (!num)
		return (0);
	num[count + ac + 1] = '\0';
	i = -1;
	j = -1;
	ch = ft_itoa(n);
	if (ch[0] == '0' && n < 0)
		num[++j] = '-';
	while (ch[++i] != '\0')
		num[++j] = ch[i];
	j++;
	ft_get_accur(&num, n, &j, ac);
	free(ch);
	num[j] = '\0';
	return (num);
}
