/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:51:11 by eclown            #+#    #+#             */
/*   Updated: 2021/12/13 20:51:21 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*copy_bonus_flags(const char **params)
{
	int		i;
	char	*flags;
	char	*bonus_flags;

	bonus_flags = malloc(256);
	if (! bonus_flags)
		return (NULL);
	flags = FT_PRINTF_FLAGS;
	i = 0;
	while (ft_strchr(flags, **params))
		bonus_flags[i++] = *(*params)++;
	bonus_flags[i] = 0;
	return (bonus_flags);
}
