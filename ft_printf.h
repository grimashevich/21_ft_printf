/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:25:19 by EClown            #+#    #+#             */
/*   Updated: 2021/12/13 21:10:36 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include	"libft/libft.h"
# include	<stddef.h>
# include	<stdarg.h>

# define FT_PRINTF_KEYS "cspdiuxX%";
# define FT_PRINTF_FLAGS "-0.# +123456789";

typedef unsigned int	t_ui;

typedef struct st_flags
{
	int		l_align;
	int		zero_fill;
	int		mod_hex;
	int		space;
	int		plus;
	size_t	min_width;
	size_t	precision;
	int		precision_on;
	char	sym;
	int		zero_char;
}	t_flags;

int			ft_printf(const char *input, ...);
char		*itos(unsigned long num, int base, char a_move);
char		*p_to_str(unsigned long p);
char		*ui_to_str(unsigned int n);
int			print_str(char *s, int need_free, int zero_c, t_flags *flags);
void		str_reverse(char *s, int last);
char		*copy_bonus_flags(const char **params);
void		ft_putstr_fd2(char *s, int fd, int byte_n_diff);
char		*char_to_str(char c);
int			process_sym(va_list *params, t_flags *flags);
const char	*pf_get_zero(const char *str);
int			pf_get_min_width(char *str);
int			pf_get_precision(char *str, t_flags *el);
t_flags		*create_sf_element(const char *params, char sym);
t_flags		*get_pf_flags(char *params, char sym);
char		*apply_flags(char *s, t_flags *flags);
char		*mp_char(char c, size_t n, char *add_str);
int			max_int(int a, int b);
char		*mod_hex(char *s, t_flags *flags);
char		*str_precision_num(char *s, size_t precision, size_t s_len);
size_t		chr_count(char *s, char c);
char		*l_align(char *str);
char		*str_width_zero(t_flags *flags, char *s);
int			print_s(char *s, t_flags *flags);
char		*str_precision(char *s, t_flags *flags);
char		*str_l_trim(char *s);
char		*add_plus_or_space2(char *s, t_flags *flags, const char *c_str);
char		*add_plus_or_space(char *s, t_flags *flags);
int			printer(char *b_flags, const char *c, va_list *prm);
t_flags		*get_pf_flags2(t_flags *flags);
char		get_base_char(unsigned int i, char a_move);
int			min_int(int a, int b);
int			print_zero_char(t_flags *flags);
void		free_free(void *v1, void *v2, void *v3, void *v3_free);
void		free_bf(void *p);

#endif
