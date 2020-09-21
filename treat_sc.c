/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_sc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:00:21 by skang             #+#    #+#             */
/*   Updated: 2020/09/21 15:00:34 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		treat(char **str, int count)
{
	char	*left;
	char	*right;

	if (g_format->minus)
	{
		left = *str;
		right = string(' ', count);
	}
	else
	{
		left = string(g_format->zero ? '0' : ' ', count);
		right = *str;
	}
	*str = ft_strjoin_with_dealloc(left, right);
}

void			treat_c(char **str, char c)
{
	int count;

	g_cnull = !c;
	if (g_cnull && g_format->minus)
	{
		ft_putchar_fd(0, 1);
		g_cnull = -1;
	}
	*str = malloc(2);
	(*str)[0] = c;
	(*str)[1] = 0;
	count = g_format->width - 1;
	if (count > 0)
		treat(str, count);
}

void			treat_s(char **str)
{
	int count;

	*str = va_arg(g_ap, char*);
	if (*str == 0)
		*str = "(null)";
	if (g_format->precision > -1)
		*str = ft_substr(*str, 0, g_format->precision);
	else
		*str = ft_strjoin(*str, "");
	count = g_format->width - (int)ft_strlen(*str);
	if (count > 0)
		treat(str, count);
}
