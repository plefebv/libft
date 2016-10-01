/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 14:16:04 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:51:30 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int			pf_hex_len(unsigned long long n)
{
	unsigned long long		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n >= 16)
	{
		n = n >> 4;
		i++;
	}
	return (i);
}

static char			pf_get_hex(t_info *info, unsigned long long n)
{
	unsigned long long	i;

	i = n & 15;
	if (i < 10)
		return (48 + i);
	else if (info->letter == 'X')
		return (55 + i);
	else if (info->letter == 'x' || info->letter == 'p')
		return (87 + i);
	else
		return (0);
}

static char			*pf_itoa_hex(unsigned long long n, t_info *info)
{
	char		*str;
	long long	i;

	i = pf_hex_len(n);
	str = ft_strnew(i + 1);
	if (str)
	{
		if (n == 0)
			str[0] = '0';
		while (n > 0)
		{
			str[i--] = pf_get_hex(info, n);
			n >>= 4;
		}
		return (str);
	}
	return (NULL);
}

static void			pf_hex_length(void *ap, t_info *info)
{
	if (ft_strcmp("hh", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_hex((unsigned char)ap, info));
	if (ft_strcmp("h", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_hex((unsigned short)ap, info));
	if (ft_strcmp("l", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_hex((unsigned long)ap, info));
	if (ft_strcmp("ll", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_hex((unsigned long long)ap, info));
	if (ft_strcmp("j", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_hex((uintmax_t)ap, info));
	if (ft_strcmp("z", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_hex((size_t)ap, info));
}

void				pf_hex(void *ap, t_info *info)
{
	int		i;

	i = 2;
	if (info->letter == 'p')
		info->length = ft_strdup("j");
	info->length ? pf_hex_length(ap, info) :
		pf_put_in_lst(info, pf_itoa_hex((unsigned)ap, info));
	pf_hex2(ap, info);
	if (info->flags && ft_strchr(info->flags, '#') && info->lst->data
				&& ft_strlen(info->lst->data) > 1 && info->lst->data[0] != ' ')
	{
		info->lst->data[1] = info->letter == 'X' ? 'X' : 'x';
		while (info->lst->data[i] != '\0'
				&& info->lst->data[i] != (info->letter == 'X' ? 'X' : 'x'))
			i++;
		if (info->lst->data[i] == 'X' || info->lst->data[i] == 'x')
			info->lst->data[i] = '0';
	}
	if (info->true_precision && !info->precision && info->minfield == 0
			&& (unsigned)ap == 0 && info->letter != 'p')
		info->lst->data[0] = '\0';
}
