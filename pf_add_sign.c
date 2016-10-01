/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_add_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 13:14:57 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:50:26 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			pf_isupper0(char c)
{
	if (c > '0' && c <= '9')
		return (1);
	return (0);
}

void		pf_add_space_diu(t_info *info)
{
	int	i;

	i = 0;
	if (info->lst->data && pf_isupper0(info->lst->data[i]))
		info->lst->data = ft_strjoin_f2(" ", info->lst->data);
	else
	{
		while (info->lst->data[i] && !(ft_isdigit(info->lst->data[i])))
			i++;
		if (i > 0 && info->lst->data[i] && ft_isdigit(info->lst->data[i]))
			info->lst->data[i - 1] = ' ';
		else
			info->lst->data[0] = ' ';
	}
}

void		pf_add_negative_di(t_info *info)
{
	int	i;

	i = 0;
	if (info->lst->data && pf_isupper0(info->lst->data[i]))
		info->lst->data = ft_strjoin_f2("-", info->lst->data);
	else
	{
		while (info->lst->data[i] && !(ft_isdigit(info->lst->data[i])))
			i++;
		if (i > 0 && info->lst->data[i] && ft_isdigit(info->lst->data[i]))
			info->lst->data[i - 1] = '-';
		else
		{
			if (pf_nbrlen_str(info->lst->data) > info->precision)
				info->lst->data[0] = '-';
			else
				info->lst->data = ft_strjoin_f2("-", info->lst->data);
		}
	}
}

void		pf_add_positive_diu(t_info *info)
{
	int	i;

	i = 0;
	if (info->lst->data && pf_isupper0(info->lst->data[i]))
		info->lst->data = ft_strjoin_f2("+", info->lst->data);
	else if (info->lst->data && !(pf_isupper0(info->lst->data[i]))
				&& (info->flags && ft_strchr(info->flags, '-')))
	{
		info->lst->data = ft_strjoin_f2("+", info->lst->data);
	}
	else
	{
		while (info->lst->data[i] && !(ft_isdigit(info->lst->data[i])))
			i++;
		if (i > 0 && info->lst->data[i] && ft_isdigit(info->lst->data[i]))
			info->lst->data[i - 1] = '+';
		else
		{
			if (ft_strcmp(info->lst->data, "0") == 0)
				info->lst->data = ft_strjoin_f2("+", info->lst->data);
			else
				info->lst->data[0] = '+';
		}
	}
}

void		pf_add_sign_diu(t_info *info)
{
	int	i;

	i = 0;
	if (info->sign == '-')
		pf_add_negative_di(info);
	if (info->flags != NULL)
	{
		if (info->sign == '+' && ft_strchr(info->flags, '+'))
			pf_add_positive_diu(info);
		if (info->sign == '+' && ft_strchr(info->flags, ' ')
				&& !(ft_strchr(info->flags, '+')))
			pf_add_space_diu(info);
	}
}
