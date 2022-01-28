/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:33:10 by eclown            #+#    #+#             */
/*   Updated: 2021/12/13 20:39:16 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_precision_num(char *s, size_t precision, size_t s_len)
{
	char	*result;
	char	*fill_str;

	if (ft_strncmp("0", s, 2) == 0 && precision == 0)
	{
		free(s);
		result = ft_strdup("");
		if (! result)
			return (NULL);
		return (result);
	}
	if (ft_strlen(s) - chr_count(s, '-') >= precision)
		return (s);
	if (s[0] == '-')
		fill_str = mp_char('0', precision - s_len + 1, "-");
	else
		fill_str = mp_char('0', precision - s_len, NULL);
	if (! fill_str)
		return (NULL);
	result = ft_strjoin(fill_str, s + chr_count(s, '-'));
	free(fill_str);
	free(s);
	return (result);
}

char	*str_precision(char *s, t_flags *flags)
{
	char	*result;
	size_t	s_len;

	s_len = ft_strlen(s);
	result = s;
	if (ft_strchr("diuxX", flags->sym))
		result = str_precision_num(result, flags->precision, s_len);
	else if (flags->sym == 's' && s_len > flags->precision)
		result[flags->precision] = 0;
	return (result);
}

char	*mod_hex(char *s, t_flags *flags)
{
	char	*result;
	int		zero_flag;
	int		i;

	i = 0;
	zero_flag = 0;
	while (s[i])
	{
		if (s[i] != '0' && s[i] != ' ')
		{
			zero_flag++;
			break ;
		}
		i++;
	}
	if (! zero_flag)
		return (s);
	if (flags->sym == 'X')
		result = ft_strjoin("0X", s);
	else
		result = ft_strjoin("0x", s);
	free(s);
	return (result);
}

char	*str_l_trim(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return (s);
}

char	*add_plus_or_space2(char *s, t_flags *flags, const char *c_str)
{
	int		i;
	char	*result;

	i = 0;
	if (flags->precision_on)
	{
		while (! ft_isdigit(s[i]))
			i++;
		s[--i] = c_str[0];
		return (s);
	}
	if (ft_strlen(s) == 1 && s[0] == '0')
	{
		result = ft_strjoin(c_str, s);
		free(s);
		return (result);
	}
	i = 0;
	while (s[i] != '0' && s[i] != ' ')
		i++;
	s[i] = c_str[0];
	return (s);
}
