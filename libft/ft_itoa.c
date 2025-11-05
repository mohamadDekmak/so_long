/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdekmak <mdekmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:58:19 by mdekmak           #+#    #+#             */
/*   Updated: 2025/05/23 08:58:19 by mdekmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	fill_result(char *result, int len, int n, int sign)
{
	int	i;

	result[len] = '\0';
	i = len - 1;
	if (n == 0)
		result[i--] = '0';
	while (n)
	{
		result[i] = '0' + sign * (n % 10);
		i--;
		n /= 10;
	}
	if (sign == -1)
		result[i] = '-';
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		temp;
	int		sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	if (n <= 0)
		len = 1;
	else
		len = 0;
	temp = n;
	while (temp)
	{
		len++;
		temp /= 10;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	fill_result(result, len, n, sign);
	return (result);
}
