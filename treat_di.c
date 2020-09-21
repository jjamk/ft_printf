/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:59:46 by skang             #+#    #+#             */
/*   Updated: 2020/09/21 15:00:10 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		treat_zero(char **str, int minus)
{
	int count;
	int len;

	len = (int)ft_strlen(*str);
	if (g_format->precision >= 0)
	{
		count = g_format->precision - len;
		if (count > 0)
			*str = ft_strjoin_with_dealloc(string('0', count), *str);
	}
	else
	{
		count = g_format->width - len;
		if (!g_format->minus && g_format->zero && count > 0)
			*str = ft_strjoin_with_dealloc(string('0', count - minus), *str);
	}
}

static void		add_sign(char **str)
{
	char *tmp;

	tmp = *str;
	*str = ft_strjoin("-", *str);
	free(tmp);
}

void			treat_space(char **str)
{
	int count;

	count = g_format->width - (int)ft_strlen(*str);
	if (count > 0)
	{
		if (g_format->minus)
			*str = ft_strjoin_with_dealloc(*str, string(' ', count));
		else
			*str = ft_strjoin_with_dealloc(string(' ', count), *str);
	}
}

void			treat_di(char **str)
{
	long long	num;
	size_t		len;
	int			minus;

	num = va_arg(g_ap, int);
	minus = (num < 0);
	*str = minus ? utoa(-num, g_base_10) : utoa(num, g_base_10);
	if (num == 0 && g_format->precision == 0)
		(*str)[0] = 0;
	len = ft_strlen(*str);
	treat_zero(str, minus);
	if (minus)
		add_sign(str);
	treat_space(str);
}
