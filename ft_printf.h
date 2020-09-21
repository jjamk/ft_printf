/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:47:55 by skang             #+#    #+#             */
/*   Updated: 2020/09/21 14:59:03 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_flags{
	int				minus;
	int				zero;
	int				width;
	int				precision;
	char				type;
}			t_flags;

extern char			*g_specifier;
extern char			*g_base_10;
extern char			*g_base_16_x;
extern char			*g_base_16_X;
extern va_list			g_ap;
extern t_flags			*g_format;
extern int			g_cnull;

int				read_flags(const char **format);
int				read_width(const char **format);
int				read_precision(const char **format);

void				treat_c(char **str, char c);
void				treat_s(char **str);
void				treat_ux(char **str, char *base);
void				treat_p(char **str);
void				treat_di(char **str);

char				*string(char c, int count);
char				*utoa(unsigned long long num, const char *base);
void				treat_with_leading_zeros(char **str, int count);
char				*ft_strjoin_with_dealloc(char *a, char *b);

#endif
