/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:48:08 by mdekmak           #+#    #+#             */
/*   Updated: 2025/05/20 20:54:33 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*d;

	i = 0;
	t = (unsigned char *)s1;
	d = (unsigned char *)s2;
	while (i < n)
	{
		if (t[i] != d[i])
			return ((int)(t[i] - d[i]));
		i++;
	}
	return (0);
}
