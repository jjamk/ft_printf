/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:57:10 by skang             #+#    #+#             */
/*   Updated: 2020/09/21 14:57:25 by skang            ###   ########.fr       */
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
		if (g_format->zero && g_format->precision == -1)
		{
			left = string('0', count);
			right = ft_strjoin(left, &(*str)[2]);
			free(left);
			free(*str);
			*str = ft_strjoin("0x", right);
			free(right);
			return ;
		}
		left = string(' ', count);
		right = *str;
	}
	*str = ft_strjoin_with_dealloc(left, right);
}

void			treat_p(char **str)
{
	int					count;
	char				*tmp;
	unsigned long long	num;

	num = (unsigned long long)va_arg(g_ap, void*);
	*str = utoa(num, g_base_16_x);
	if (num == 0 && g_format->precision == 0)
		(*str)[0] = 0;
	count = g_format->precision - (int)ft_strlen(*str);
	if (count > 0)
		treat_with_leading_zeros(str, count);
	tmp = *str;
	*str = ft_strjoin("0x", *str);
	free(tmp);
	count = g_format->width - (int)ft_strlen(*str);
	if (count > 0)
		treat(str, count);
}
