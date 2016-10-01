/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_c.c                                         :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 12:24:56 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:54:52 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void			pf_convert_to_wchar(wchar_t ap, t_info *info)
{
	if (ap < 128)
		info->lst->data[0] = ((ap >> 0) & 127) | 0;
	else if (ap < 2048)
	{
		info->lst->data[0] = ((ap >> 6) & 31) | 192;
		info->lst->data[1] = ((ap >> 0) & 63) | 128;
	}
	else if (ap < 65536)
	{
		info->lst->data[0] = ((ap >> 12) & 15) | 224;
		info->lst->data[1] = ((ap >> 6) & 63) | 128;
		info->lst->data[2] = ((ap >> 0) & 63) | 128;
	}
	else if (ap < 1114112)
	{
		info->lst->data[0] = ((ap >> 18) & 7) | 240;
		info->lst->data[1] = ((ap >> 12) & 63) | 128;
		info->lst->data[2] = ((ap >> 6) & 63) | 128;
		info->lst->data[3] = ((ap >> 0) & 63) | 128;
	}
}

void				pf_put_wc(wchar_t ap, t_info *info)
{
	if (ap < 1114112)
	{
		free(info->lst->data);
		if (ap < 128)
			info->lst->data = ft_strnew(1);
		else if (ap < 2048)
			info->lst->data = ft_strnew(2);
		else if (ap < 65536)
			info->lst->data = ft_strnew(3);
		else if (ap < 1114112)
			info->lst->data = ft_strnew(4);
		pf_convert_to_wchar(ap, info);
	}
}

void				pf_put_char(char ap, t_info *info)
{
	char tmp[2];

	tmp[1] = '\0';
	tmp[0] = ap;
	free(info->lst->data);
	info->lst->data = (char *)malloc(sizeof(char) * 2);
	if (info->lst->data)
	{
		info->lst->data[0] = ap;
		info->lst->data[1] = '\0';
	}
}
