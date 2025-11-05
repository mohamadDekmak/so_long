/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:34:57 by mdekmak           #+#    #+#             */
/*   Updated: 2025/05/21 09:25:58 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	z;

	j = 0;
	if (*little == '\0')
		return ((char *)(big));
	while (big[j] && j < len)
	{
		i = 0;
		z = j;
		while (little[i] && big[z] && (j + i) < len)
		{
			if (little[i] != big[z])
				break ;
			i++;
			z++;
		}
		if (!little[i])
			return ((char *)(big + j));
		j++;
	}
	return (NULL);
}
