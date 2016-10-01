/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 13:03:51 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:50:41 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		pf_di_length(void *ap, t_info *info)
{
	if (ft_strcmp("hh", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_ll((char)ap, info));
	else if (ft_strcmp("h", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_ll((short)ap, info));
	else if (ft_strcmp("l", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_ll((long)ap, info));
	else if (ft_strcmp("ll", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_ll((long long)ap, info));
	else if (ft_strcmp("j", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_ll((intmax_t)ap, info));
	else if (ft_strcmp("z", info->length) == 0)
		pf_put_in_lst(info, pf_itoa_ll((size_t)ap, info));
}

void		pf_di(void *ap, t_info *info)
{
	int		i;

	i = 0;
	info->length ? pf_di_length(ap, info) :
	pf_put_in_lst(info, pf_itoa_ll((signed)ap, info));
	if (info->true_precision)
		pf_precision_dioux(ap, info);
	if (info->minfield > 0)
		pf_minfield(info);
	pf_add_sign_diu(info);
}
