/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_precision_dioux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:40:25 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:54:20 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		pf_add_char(char **s, int add, char c)
{
	int		i;

	i = 0;
	while (i < add)
		s[0][i++] = c;
}

void		pf_add_precision_dioux(t_info *info, int add)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * (add + 1));
	if (s)
	{
		s[add] = '\0';
		pf_add_char(&s, add, '0');
		info->lst->data = ft_strjoin_f(s, info->lst->data);
	}
}

void		pf_precision_dioux(void *ap, t_info *info)
{
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(info->lst->data);
	if (size < info->precision)
		pf_add_precision_dioux(info, info->precision - size);
	if (!info->precision && (int)ap == 0)
	{
		while (info->lst->data && info->lst->data[i] != '\0')
		{
			if (info->lst->data[i] == '0')
			{
				if (info->minfield > 0)
					info->lst->data[i] = ' ';
				else
					info->lst->data[i] = '\0';
			}
			i++;
		}
	}
}

void		pf_precision_p(void *ap, t_info *info)
{
	int		size;
	int		i;

	i = -1;
	size = ft_strlen(info->lst->data);
	if (size < info->precision + 2)
		pf_add_precision_dioux(info, info->precision - size + 2);
	if (!info->precision && (int)ap == 0)
	{
		while (info->lst->data && info->lst->data[++i] != '\0')
		{
			if (info->lst->data[i] == '0')
			{
				if (info->minfield > 0)
					info->lst->data[i] = ' ';
				else
					info->lst->data[i] = '\0';
			}
		}
	}
	i = 1;
	info->lst->data[1] = 'x';
	while (info->lst->data[++i])
		if (info->lst->data[i] == 'x')
			info->lst->data[i] = '0';
}
