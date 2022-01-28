/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:19:40 by eclown            #+#    #+#             */
/*   Updated: 2021/12/13 20:27:31 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_reverse(char *s, int last)
{
	int		j;
	char	c;

	j = 0;
	while (last > j)
	{
		c = s[last];
		s[last--] = s[j];
		s[j++] = c;
	}
}

char	get_base_char(unsigned int i, char a_move)
{
	if (i <= 9)
		return ((char)(i + 48));
	return ((char)(i + a_move));
}

char	*itos(unsigned long num, int base, char a_move)
{
	char	*result;
	int		i;

	if (base < 2)
		return (NULL);
	result = malloc(20);
	if (result == NULL)
		return (NULL);
	i = 0;
	if (num == 0)
		result[i++] = '0';
	while (num)
	{
		result[i++] = get_base_char(num % base, a_move);
		num = num / base;
	}
	result[i--] = 0;
	str_reverse(result, i);
	return (result);
}

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
