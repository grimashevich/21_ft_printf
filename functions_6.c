/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:40:24 by eclown            #+#    #+#             */
/*   Updated: 2021/12/13 21:36:46 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_bf(void *p)
{
	if (p)
		free(p);
}

int	printer(char *b_flags, const char *c, va_list *prm)
{
	char	*pf_keys;
	char	*key;
	t_flags	*flags;

	pf_keys = FT_PRINTF_KEYS;
	key = ft_strchr(pf_keys, *c);
	flags = get_pf_flags(b_flags, *key);
	free_bf(b_flags);
	if (*key == 'c')
		return (process_sym(prm, flags));
	else if (*key == 's')
		return (print_s(va_arg(*prm, char *), flags));
	else if (*key == 'p')
		return (print_str(p_to_str(va_arg(*prm, unsigned long)), 1, 0, flags));
	else if (*key == 'd' || *key == 'i')
		return (print_str(ft_itoa(va_arg(*prm, int)), 1, 0, flags));
	else if (*key == 'u')
		return (print_str(ui_to_str(va_arg(*prm, int)), 1, 0, flags));
	else if (*key == 'x')
		return (print_str(itos((va_arg(*prm, t_ui)), 16, 87), 1, 0, flags));
	else if (*key == 'X')
		return (print_str(itos((va_arg(*prm, t_ui)), 16, 55), 1, 0, flags));
	else if (*key == '%')
		return (print_str(ft_strdup("%"), 1, 0, flags));
	return (0);
}

t_flags	*get_pf_flags2(t_flags *flags)
{
	if (flags->l_align || flags->precision_on)
		flags->zero_fill = 0;
	if (flags->plus)
		flags->space = 0;
	return (flags);
}

t_flags	*get_pf_flags(char *params, char sym)
{
	char	*pf_keys;
	t_flags	*el;

	el = create_sf_element(params, sym);
	if (el == NULL)
		return (NULL);
	pf_keys = FT_PRINTF_KEYS;
	if (! ft_strchr(pf_keys, sym))
		return (NULL);
	el->sym = sym;
	if (ft_strchr(params, '-'))
		el->l_align = 1;
	if (ft_strchr(params, '#'))
		el->mod_hex = 1;
	if (ft_strchr(params, ' '))
		el->space = 1;
	if (ft_strchr(params, '+'))
		el->plus = 1;
	if (pf_get_zero(params))
		el->zero_fill = 1;
	el->min_width = pf_get_min_width(params);
	el->precision = pf_get_precision(params, el);
	el = get_pf_flags2(el);
	return (el);
}
