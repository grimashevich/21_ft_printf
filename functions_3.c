/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:30:01 by eclown            #+#    #+#             */
/*   Updated: 2021/12/13 20:32:36 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ui_to_str(unsigned int n)
{
	char	*digs;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	digs = malloc(11);
	if (!digs)
		return (NULL);
	while (n)
	{
		digs[i] = (char)((n % 10) + 48);
		n = n / 10;
		i++;
	}
	digs[i--] = 0;
	str_reverse(digs, i);
	return (digs);
}

char	*p_to_str(unsigned long p)
{
	char	*hex;
	char	*result;

	if (p == 0)
		return (ft_strdup("0x0"));
	hex = itos(p, 16, 87);
	if (hex == NULL)
		return (NULL);
	result = ft_strjoin("0x", hex);
	if (result == NULL)
	{
		free(hex);
		return (NULL);
	}
	free(hex);
	return (result);
}

char	*mp_char(char c, size_t n, char *add_str)
{
	char	*result;
	char	*result2;

	if (n == 0)
		return (NULL);
	result = malloc(n + 1);
	if (! result)
		return (NULL);
	result[n--] = 0;
	while (n > 0)
		result[n--] = c;
	result[0] = c;
	if (add_str && *add_str)
	{
		result2 = ft_strjoin(add_str, result);
		free(result);
		return (result2);
	}
	return (result);
}

char	*str_width_zero(t_flags *flags, char *s)
{
	char	*result;
	char	*fill_str;

	if (ft_strchr("diuxX%", flags->sym) && flags->zero_fill)
	{
		result = str_precision_num(s, flags->min_width - chr_count(s, '-'), \
									ft_strlen(s));
		if (!result)
			return (NULL);
	}
	else
	{
		fill_str = mp_char(' ', flags->min_width - ft_strlen(s) - \
					flags->zero_char, NULL);
		if (! fill_str)
			return (NULL);
		result = ft_strjoin(fill_str, s);
		free(fill_str);
		free(s);
	}
	return (result);
}

size_t	chr_count(char *s, char c)
{
	size_t	result;

	result = 0;
	while (*s)
	{
		if (*s++ == c)
			result++;
	}
	return (result);
}
