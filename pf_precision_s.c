/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_precision_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 11:35:50 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 15:52:33 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		pf_precision_s(t_pffo *pffo)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (pffo->true_precision && pffo->precision >= 0)
	{
		str = ft_strnew(pffo->precision + 1);
		while (pffo->lst->data[i] != '\0' && i < pffo->precision)
		{
			str[i] = pffo->lst->data[i];
			i++;
		}
		free(pffo->lst->data);
		pffo->lst->data = str;
	}
}
