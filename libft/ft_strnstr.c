/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:59:08 by mdenyse           #+#    #+#             */
/*   Updated: 2021/04/16 16:59:10 by mdenyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while ((i < len) && (haystack[i] != '\0'))
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while ((haystack[i + j] == needle[j])
				&& (haystack[i + j] != '\0') && (needle[j] != '\0'))
			{
				j++;
			}
			if (needle[j] == '\0' && (i + j) <= len)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}
