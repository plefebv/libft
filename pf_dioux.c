/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dioux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 19:57:48 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:50:52 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		pf_dioux(void *ap, t_info *info)
{
	if (info->letter == 'd' || info->letter == 'i')
		pf_di(ap, info);
	else if (info->letter == 'u')
		pf_u(ap, info);
	else if (info->letter == 'x' || info->letter == 'X' || info->letter == 'p')
		pf_hex(ap, info);
	else if (info->letter == 'o')
		pf_octal(ap, info);
}
