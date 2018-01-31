/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 16:36:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/12/26 16:36:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAG "#0+- "
# define FORMAT "sSpdDioOuUxXcCnb"
# define MOD "hljzL"
# define HEX_SYMBOLS "0123456789ABCDEF"

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <wchar.h>

typedef struct		s_specinfo
{
	char	format;
	char	sharp;
	char	zero_minus;
	char	plus_space;
	int		width;
	int		precision;
	int		mod_h;
	int		mod_l;
	int		mod_j;
	int		mod_z;
	int		mod_l_up;
}					t_specinfo;

int					ft_printf(const char *format, ...);
void				specificator_manager(char **format, int *len,
									va_list *args);
void				print_manager(t_specinfo *info, int *len,
									va_list *args);
void				ft_printf_getcolor(char **str, int *len);
void				ft_specinfo_init(t_specinfo *info);

void				format_s(t_specinfo *info, int *len, va_list *args);
void				format_s_wchar(t_specinfo *info, int *len, va_list *args);
void				format_p(t_specinfo *info, int *len, va_list *args);
void				format_c_putchar(t_specinfo *info, int *len,
									unsigned char c);
void				format_c(t_specinfo *info, int *len, va_list *args);
void				format_c_putwchar(t_specinfo *info, int *len, wchar_t wc);
void				format_s_putstr(t_specinfo *info, int *len, char *str);
void				format_d_i(t_specinfo *info, int *len, va_list *args);
void				format_n(t_specinfo *info, int *len, va_list *args);
void				format_o(t_specinfo *info, int *len, va_list *args);
void				format_x(t_specinfo *info, int *len, va_list *args);
void				format_u(t_specinfo *info, int *len, va_list *args);
void				format_b(t_specinfo *info, int *len, va_list *args);

void				ft_printf_cast_unum(t_specinfo *info, uintmax_t *num,
									va_list *args);
void				format_x_print(t_specinfo *info, char *str, short str_len,
									short space_len);
#endif
