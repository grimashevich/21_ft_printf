/* ************************************************************************** */
/*																			  */
/*														:::	  ::::::::   	 */
/*   functions_0.c									  :+:	  :+:	:+:      */
/*													+:+ +:+		 +:+	 */
/*   By: eclown <eclown@student.21-school.ru>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/12/04 13:36:01 by eclown			#+#	#+#			 */
/*   Updated: 2021/12/04 17:20:27 by eclown		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	print_zero_char(t_flags *flags)
{
	size_t	i;

	i = 0;
	if (flags->l_align)
		ft_putchar_fd(0, 1);
	if (flags->min_width)
	{
		while (i++ < flags->min_width - 1)
			ft_putchar_fd(' ', 1);
	}
	if (! flags->l_align)
		ft_putchar_fd(0, 1);
	free(flags);
	if (flags->min_width)
		return ((int) flags->min_width);
	return (1);
}

void	free_free(void *v1, void *v2, void *v3, void *v3_free)
{
	free(v1);
	free(v2);
	if (v3_free == NULL)
		free(v3);
}

int	print_s(char *s, t_flags *flags)
{
	char	*result;
	char	*spaces;
	int		print_len;
	int		res_num;

	result = s;
	if (s == NULL)
		result = ft_strdup("(null)");
	print_len = (int) ft_strlen(result);
	if (flags->precision_on)
		print_len = min_int((int) ft_strlen(result), (int) flags->precision);
	spaces = mp_char(' ', max_int((int)(flags->min_width - print_len) \
						, 0), NULL);
	if (flags->l_align)
		write(1, result, print_len);
	if (spaces != NULL)
		ft_putstr_fd(spaces, 1);
	if (! flags->l_align)
		write(1, result, print_len);
	res_num = print_len;
	if (spaces != NULL)
		res_num += (int) ft_strlen(spaces);
	free_free(flags, spaces, result, s);
	return (res_num);
}

int	process_sym(va_list *params, t_flags *flags)
{
	char	sym;

	sym = (char) va_arg(*params, int);
	if (sym == 0)
		return (print_zero_char(flags));
	return (print_str(char_to_str(sym), 1, 0, flags));
}

void	ft_putstr_fd2(char *s, int fd, int byte_n_diff)
{
	if (!s)
		return ;
	write(fd, &s[0], ft_strlen(s) + byte_n_diff);
}
