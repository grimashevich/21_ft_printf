/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:20:01 by eclown            #+#    #+#             */
/*   Updated: 2021/12/13 20:20:38 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_get_precision(char *str, t_flags *el)
{
	if (ft_strchr(str, '.'))
		el->precision_on = 1;
	while (*str != '.')
	{
		if (*str == 0)
			return (0);
		str++;
	}
	return (ft_atoi(++str));
}

int	pf_get_min_width(char *str)
{
	while (! ft_isdigit(*str) || *str == '0')
	{
		if (*str == '.' || *str == 0)
			return (0);
		str++;
	}
	return (ft_atoi(str));
}

const char	*pf_get_zero(const char *str)
{
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		if (ft_isdigit(*str) && *str != '0' )
			return (NULL);
		if (*str == '.')
			return (NULL);
		if (*str == '0')
			return (str);
		str++;
	}
	return (NULL);
}

t_flags	*create_sf_element(const char *params, char sym)
{
	t_flags	*el;

	if (params == NULL || sym == 0)
		return (NULL);
	el = malloc(sizeof(t_flags));
	if (el == NULL)
		return (NULL);
	el->sym = 0;
	el->l_align = 0;
	el->min_width = 0;
	el->mod_hex = 0;
	el->precision = 0;
	el->precision_on = 0;
	el->space = 0;
	el->zero_fill = 0;
	el->plus = 0;
	el->zero_char = 0;
	return (el);
}

int	ft_printf(const char *input, ...)
{
	va_list	params;
	int		result;

	result = 0;
	va_start(params, input);
	while (*input)
	{
		if (*input == '%' && input++ != NULL)
			result += printer(copy_bonus_flags(&input), input, &params);
		else
		{
			ft_putchar_fd(*input, 1);
			result++;
		}
		input++;
	}
	va_end(params);
	return (result);
}
