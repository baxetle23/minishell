/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:26:23 by mdenyse           #+#    #+#             */
/*   Updated: 2021/04/18 10:26:25 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_instr(char c, char const *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_check(char const *s)
{
	if (s == NULL)
		return (0);
	if (s[0] == '\0')
		return ("");
	return ("1");
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	if (!ft_check(s1))
		return ((char *)s1);
	i = 0;
	while (ft_instr(s1[i], set) && s1[i] != '\0')
		i++;
	j = ft_strlen(s1) - 1;
	if (i != j + 1)
		while (ft_instr(s1[j], set) && j >= 0)
			j--;
	len = j - i + 1;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	j = 0;
	while (j < len)
		res[j++] = s1[i++];
	res[j] = '\0';
	return (res);
}
