/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 06:57:21 by mdekmak           #+#    #+#             */
/*   Updated: 2025/05/23 06:57:21 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	size_t			i;

	if (s && (size_t)start >= ft_strlen(s))
	{
		result = (char *)malloc(sizeof(char));
		if (s == NULL || result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < (unsigned int)len)
	{
		result[i] = s[i + (size_t)start];
		i++;
	}
	result[i] = '\0';
	return (result);
}
