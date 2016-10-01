/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_precision_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 11:35:50 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:54:38 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		pf_precision_s(t_info *info)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (info->true_precision && info->precision >= 0)
	{
		str = ft_strnew(info->precision + 1);
		while (info->lst->data[i] != '\0' && i < info->precision)
		{
			str[i] = info->lst->data[i];
			i++;
		}
		free(info->lst->data);
		info->lst->data = str;
	}
}
