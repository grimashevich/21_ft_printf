/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:39:38 by eclown            #+#    #+#             */
/*   Updated: 2021/12/13 20:40:06 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_plus_or_space(char *s, t_flags *flags)
{
	char	c_str[2];
	char	*result;

	if (ft_tolower(flags->sym) == 'x')
		return (s);
	c_str[1] = 0;
	c_str[0] = ' ';
	if (flags->plus)
		c_str[0] = '+';
	if (*str_l_trim(s) == '-')
		return (s);
	if ((ft_isdigit(s[0]) && flags->precision_on) || \
		(flags->precision_on == 0 && ft_isdigit(s[0]) && s[0] != '0'))
	{
		result = ft_strjoin(c_str, s);
		free(s);
		return (result);
	}
	return (add_plus_or_space2(s, flags, c_str));
}

char	*l_align(char *str)
{
	int		space_len;
	char	*spaces;
	char	*result;

	space_len = 0;
	while (str[space_len] == ' ')
		space_len++;
	if (space_len == 0 || str[space_len] == 0)
		return (str);
	spaces = mp_char(' ', space_len, NULL);
	result = ft_strjoin(&str[space_len], spaces);
	free(spaces);
	free(str);
	return (result);
}

char	*apply_flags(char *s, t_flags *flags)
{
	char	*result;

	if (! flags)
		return (s);
	result = s;
	if (flags->precision_on)
		result = str_precision(s, flags);
	if (flags->mod_hex && ft_tolower(flags->sym) == 'x')
		result = mod_hex(result, flags);
	if (flags->min_width > ft_strlen(result))
		result = str_width_zero(flags, result);
	if ((flags->plus || flags->space) && ft_strchr("diuxX", flags->sym))
		result = add_plus_or_space(result, flags);
	if (flags->l_align)
		result = l_align(result);
	return (result);
}

int	print_str(char *s, int need_free, int zero_c, t_flags *flags)
{
	int		len;

	if (s == NULL)
	{
		s = ft_strdup("(null)");
		need_free = 1;
	}
	s = apply_flags(s, flags);
	ft_putstr_fd2(s, 1, zero_c);
	len = (int) ft_strlen(s) + zero_c;
	if (need_free)
		free(s);
	free(flags);
	return (len);
}

char	*char_to_str(char c)
{
	char	*c_str;

	c_str = malloc(2);
	if (! c_str)
		return (NULL);
	c_str[0] = c;
	c_str[1] = 0;
	return (c_str);
}
