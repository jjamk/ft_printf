/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:48:50 by skang             #+#    #+#             */
/*   Updated: 2020/09/21 14:58:45 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*g_specifier = "cspdiuxX%";
char			*g_base_10 = "0123456789";
char			*g_base_16_x = "0123456789abcdef";
char			*g_base_16_X = "0123456789ABCDEF";
t_flags			*g_format;
va_list			g_ap;
int			g_cnull;

char			*get_format_string(void)
{
	char t;
	char *format_str;

	t = g_format->type;
	if (t == 'c')
		treat_c(&format_str, va_arg(g_ap, int));
	else if (t == 's')
		treat_s(&format_str);
	else if (t == 'u')
		treat_ux(&format_str, g_base_10);
	else if (t == 'x')
		treat_ux(&format_str, g_base_16_x);
	else if (t == 'X')
		treat_ux(&format_str, g_base_16_X);
	else if (t == 'p')
		treat_p(&format_str);
	else if (t == 'd' || t == 'i')
		treat_di(&format_str);
	else
		treat_c(&format_str, t);
	return (format_str);
}

static void		init(void)
{
	g_format->minus = 0;
	g_format->zero = 0;
	g_format->width = 0;
	g_format->precision = -1;
	g_format->type = 0;
}

void			parse(const char *format, char *str, size_t *len)
{
	while (*format)
		if (*format == '%')
		{
			g_cnull = 0;
			++format;
			init();
			while (read_flags(&format) || read_width(&format) ||
			read_precision(&format))
				; //바꾼부분
			if (!(g_format->type = *(format++)))
				break ;
			str = get_format_string();
			*len += ft_strlen(str) + (g_cnull != 0);
			ft_putstr_fd(str, 1);
			free(str);
			str = 0;
			if (g_cnull > 0)
				ft_putchar_fd(0, 1);
		}
		else
		{
			ft_putchar_fd(*format++, 1);
			++(*len);
		}
}

int			ft_printf(const char *format, ...)
{
	size_t res;

	res = 0;
	g_format = malloc(sizeof(t_flags));
	va_start(g_ap, format);
	parse(format, 0, &res);
	va_end(g_ap);
	free(g_format);
	return ((int)res);
}
