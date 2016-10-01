/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 13:04:59 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:55:50 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void		pf_u_length(void *ap, t_info *info)
{
	if (ft_strcmp("hh", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_ull((unsigned char)ap));
	if (ft_strcmp("h", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_ull((unsigned short)ap));
	if (ft_strcmp("l", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_ull((unsigned long)ap));
	if (ft_strcmp("ll", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_ull((unsigned long long)ap));
	if (ft_strcmp("j", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_ull((uintmax_t)ap));
	if (ft_strcmp("z", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_ull((size_t)ap));
}

void			pf_u(void *ap, t_info *info)
{
	int		i;

	i = 0;
	info->length ? pf_u_length(ap, info) :
		pf_put_in_lst(info, pf_itoa_ull((unsigned)ap));
	if (info->true_precision)
		pf_precision_dioux(ap, info);
	if (info->minfield > 0)
		pf_minfield(info);
}
