/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <skang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:50:41 by skang             #+#    #+#             */
/*   Updated: 2020/09/21 14:50:48 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*string(char c, int count)
{
	char *str;

	str = malloc(count + 1);
	str[count] = 0;
	while (count--)
		str[count] = c;
	return (str);
}

static int	get_nbr_len(long long num, int base_len)
{
	return (num ? 1 + get_nbr_len(num / base_len, base_len) : 0);
}

char		*utoa(unsigned long long num, const char *base)
{
	int		len;
	char	*res;
	int		base_len;

	base_len = (int)ft_strlen(base);
	len = 1 + get_nbr_len(num / base_len, base_len);
	res = malloc(len + 1);
	res[len] = 0;
	while (--len >= 0)
	{
		res[len] = base[(num % base_len)];
		num /= base_len;
	}
	return (res);
}

void		treat_with_leading_zeros(char **str, int count)
{
	char *left;
	char *right;

	left = string('0', count);
	right = *str;
	*str = ft_strjoin_with_dealloc(left, right);
}

char		*ft_strjoin_with_dealloc(char *a, char *b)
{
	char	*res;

	res = ft_strjoin(a, b);
	free(a);
	free(b);
	return (res);
}
