/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_first_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 18:02:07 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:51:06 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		pf_stars(int value, t_info *info, int *i, const char *fmt)
{
	if (info->star_minfield)
	{
		info->minfield = value;
		(info->star_minfield)--;
		(info->stars)--;
	}
	else if (info->star_precision)
	{
		info->precision = value;
		(info->star_precision)--;
		(info->stars)--;
	}
	while (ft_isdigit(fmt[*i]))
		(*i)++;
}

void		pf_clean_info(t_info *info)
{
	if (info->flags)
		ft_memdel((void **)&info->flags);
	info->minfield = 0;
	info->star_minfield = 0;
	info->true_precision = 0;
	info->precision = 0;
	info->star_precision = 0;
	if (info->length)
		ft_memdel((void **)&info->length);
	info->letter = '?';
	info->stars = 0;
	info->sign = '+';
}

void		pf_epur_fmt(t_info *info, const char *fmt, int *i)
{
	int		tmp;
	char	*data;

	tmp = *i;
	data = NULL;
	while (fmt[*i] && fmt[*i] != '%')
		*i += 1;
	data = ft_strsub(fmt, tmp, *i - tmp);
	if (ft_strlen(data))
		pf_put_in_lst(&info[0], data);
	else
		ft_memdel((void **)&data);
}

int			pf_dio(t_info *info)
{
	if (info->letter == 'd' || info->letter == 'i')
		return (1);
	return (0);
}
