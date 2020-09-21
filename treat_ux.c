/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_ux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:59:13 by skang             #+#    #+#             */
/*   Updated: 2020/09/21 14:59:35 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		treat(char **str, int count)
{
	char	*left;
	char	*right;
	char	c;

	if (g_format->minus)
	{
		left = *str;
		right = string(' ', count);
	}
	else
	{
		c = g_format->zero && g_format->precision < 0 ? '0' : ' ';
		left = string(c, count);
		right = *str;
	}
	*str = ft_strjoin_with_dealloc(left, right);
}

void			treat_ux(char **str, char *base)
{
	int				count;
	unsigned int	num;

	num = va_arg(g_ap, unsigned int);
	*str = utoa(num, base);
	if (num == 0 && g_format->precision == 0)
		(*str)[0] = 0;
	count = g_format->precision - (int)ft_strlen(*str);
	if (count > 0)
		treat_with_leading_zeros(str, count);
	count = g_format->width - (int)ft_strlen(*str);
	if (count > 0)
		treat(str, count);
}
