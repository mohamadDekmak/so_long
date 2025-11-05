/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:29:25 by mdekmak           #+#    #+#             */
/*   Updated: 2025/05/23 08:29:25 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	word_count;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			word_count++;
		i++;
	}
	return (word_count);
}

void	get_result(char const *s, char c, char **result, int *j)
{
	int	i;
	int	k;

	i = 0;
	*j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = i;
			while (s[k] && s[k] != c)
				k++;
			result[*j] = (char *)malloc(sizeof(char) * (k - i + 1));
			if (result[*j] == NULL)
				return ;
			k = 0;
			while (s[i] && s[i] != c)
				result[*j][k++] = s[i++];
			result[*j][k] = '\0';
			(*j)++;
		}
		else
			i++;
	}
	result[*j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		j;

	if (s == NULL)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (result == NULL)
		return (NULL);
	get_result(s, c, result, &j);
	return (result);
}
