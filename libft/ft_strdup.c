/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:06:25 by mdenyse           #+#    #+#             */
/*   Updated: 2021/04/17 18:06:27 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1, int start, int len)
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
