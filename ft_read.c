/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:49:27 by skang             #+#    #+#             */
/*   Updated: 2020/09/21 14:49:38 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		read_flags(const char **format)
{
	char c;

	c = **format;
	if (c == '-')
		g_format->minus = 1;
	else if (c == '0')
		g_format->zero = 1;
	else
		return (0);
	++(*format);
	return (1);
}

int		read_width(const char **format)
{
	char c;

	c = **format;
	if (c == '*')
	{
		g_format->width = va_arg(g_ap, int);
		if (g_format->width < 0)
		{
			g_format->minus = 1;
			g_format->width *= -1;
		}
		++(*format);
	}
	else if (ft_isdigit(c))
	{
		g_format->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			++(*format);
	}
	else
		return (0);
	return (1);
}

int		read_precision(const char **format)
{
	char c;

	if (**format != '.')
		return (0);
	c = *(++(*format));
	g_format->precision = 0;
	if (c == '*')
	{
		g_format->precision = va_arg(g_ap, int);
		++(*format);
	}
	else if (ft_isdigit(c))
	{
		g_format->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			++(*format);
	}
	return (1);
}
