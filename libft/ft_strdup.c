/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 06:53:05 by mdekmak           #+#    #+#             */
/*   Updated: 2025/05/23 07:22:27 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*res;
	int			s_len;
	int			i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (s_len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
