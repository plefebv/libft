/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 16:12:34 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:53:40 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		pf_octal_len(unsigned long long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n >= 8)
	{
		n = n / 8;
		i++;
	}
	return (i);
}

static char		*pf_itoa_octal(unsigned long long n)
{
	char		*str;
	long long	i;

	i = pf_octal_len(n);
	str = ft_strnew(i + 1);
	if (str)
	{
		if (n == 0)
			str[0] = '0';
		while (n > 0)
		{
			str[i--] = (n % 8) + 48;
			n /= 8;
		}
		return (str);
	}
	return (NULL);
}

static void		pf_octal_length(void *ap, t_info *info)
{
	if (ft_strcmp("hh", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_octal((unsigned char)ap));
	if (ft_strcmp("h", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_octal((unsigned short)ap));
	if (ft_strcmp("l", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_octal((unsigned long)ap));
	if (ft_strcmp("ll", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_octal((unsigned long long)ap));
	if (ft_strcmp("j", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_octal((uintmax_t)ap));
	if (ft_strcmp("z", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_octal((size_t)ap));
}

void			pf_octal(void *ap, t_info *info)
{
	int		i;

	i = 0;
	info->length ? pf_octal_length(ap, info) :
		pf_put_in_lst(info, pf_itoa_octal((unsigned)ap));
	if (info->flags && ft_strchr(info->flags, '#') && info->lst->data[0] != '0')
		info->lst->data = ft_strjoin_f2("0", info->lst->data);
	if (info->true_precision && info->precision && (int)ap != 0)
		pf_precision_dioux(ap, info);
	if (info->true_precision && !info->precision && (int)ap == 0)
	{
		free(info->lst->data);
		if (info->flags && ft_strchr(info->flags, '#'))
			info->lst->data = ft_strdup("0");
		else
			info->lst->data = ft_strdup("");
	}
	if (info->minfield > 0)
		pf_minfield(info);
}
