/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:26:42 by mdenyse           #+#    #+#             */
/*   Updated: 2021/04/18 10:26:44 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len_w(char const *s, int i, char c)
{
	int	j;

	while (s[i] == c)
		i++;
	j = i;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i - j);
}

static int	ft_get_count_w(char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_get_words(char **res, const char *s, int count, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (k < count)
	{
		j = 0;
		res[k] = (char *)malloc(sizeof(char) * (ft_get_len_w(s, i, c) + 1));
		if (!res[k])
			return (0);
		while (s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			res[k][j] = s[i];
			i++;
			j++;
		}
		res[k][j] = '\0';
		k++;
	}
	res[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**res;

	if (s == NULL)
		return (0);
	count = ft_get_count_w(s, c);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (0);
	if (ft_get_words(res, s, count, c))
		return (res);
	return (0);
}
