/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:11:37 by mdekmak           #+#    #+#             */
/*   Updated: 2025/05/21 08:31:02 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*p;
	char		*cur;
	const char	*t;

	cur = ft_strchr(s, c);
	p = cur;
	t = s;
	while (*t && cur)
	{
		t++;
		p = cur;
		cur = ft_strchr(t, c);
	}
	return (p);
}
