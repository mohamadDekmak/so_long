/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:01:06 by mdekmak           #+#    #+#             */
/*   Updated: 2025/05/21 09:19:32 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*t;

	t = s;
	while (*t)
	{
		if (*t == (const char)c)
			return ((char *)t);
		t++;
	}
	if (*t == (const char)c)
		return ((char *)t);
	return (NULL);
}
