/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:57:20 by mdenyse           #+#    #+#             */
/*   Updated: 2021/04/17 18:57:22 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (s == NULL)
		return (0);
	if (ft_strlen(s) < start)
	{
		res = (char *)malloc(sizeof(char));
		res[0] = '\0';
		return (res);
	}
	if ((len + start) > ft_strlen(s))
		res = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
