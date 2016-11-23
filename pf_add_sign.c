/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_add_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 13:14:57 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 15:52:33 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			pf_isupper0(char c)
{
	if (c > '0' && c <= '9')
		return (1);
	return (0);
}

void		pf_add_space_diu(t_pffo *pffo)
{
	int	i;

	i = 0;
	if (pffo->lst->data && pf_isupper0(pffo->lst->data[i]))
		pffo->lst->data = ft_strjoin_f2(" ", pffo->lst->data);
	else
	{
		while (pffo->lst->data[i] && !(ft_isdigit(pffo->lst->data[i])))
			i++;
		if (i > 0 && pffo->lst->data[i] && ft_isdigit(pffo->lst->data[i]))
			pffo->lst->data[i - 1] = ' ';
		else
			pffo->lst->data[0] = ' ';
	}
}

void		pf_add_negative_di(t_pffo *pffo)
{
	int	i;

	i = 0;
	if (pffo->lst->data && pf_isupper0(pffo->lst->data[i]))
		pffo->lst->data = ft_strjoin_f2("-", pffo->lst->data);
	else
	{
		while (pffo->lst->data[i] && !(ft_isdigit(pffo->lst->data[i])))
			i++;
		if (i > 0 && pffo->lst->data[i] && ft_isdigit(pffo->lst->data[i]))
			pffo->lst->data[i - 1] = '-';
		else
		{
			if (pf_nbrlen_str(pffo->lst->data) > pffo->precision)
				pffo->lst->data[0] = '-';
			else
				pffo->lst->data = ft_strjoin_f2("-", pffo->lst->data);
		}
	}
}

void		pf_add_positive_diu(t_pffo *pffo)
{
	int	i;

	i = 0;
	if (pffo->lst->data && pf_isupper0(pffo->lst->data[i]))
		pffo->lst->data = ft_strjoin_f2("+", pffo->lst->data);
	else if (pffo->lst->data && !(pf_isupper0(pffo->lst->data[i]))
				&& (pffo->flags && ft_strchr(pffo->flags, '-')))
	{
		pffo->lst->data = ft_strjoin_f2("+", pffo->lst->data);
	}
	else
	{
		while (pffo->lst->data[i] && !(ft_isdigit(pffo->lst->data[i])))
			i++;
		if (i > 0 && pffo->lst->data[i] && ft_isdigit(pffo->lst->data[i]))
			pffo->lst->data[i - 1] = '+';
		else
		{
			if (ft_strcmp(pffo->lst->data, "0") == 0)
				pffo->lst->data = ft_strjoin_f2("+", pffo->lst->data);
			else
				pffo->lst->data[0] = '+';
		}
	}
}

void		pf_add_sign_diu(t_pffo *pffo)
{
	int	i;

	i = 0;
	if (pffo->sign == '-')
		pf_add_negative_di(pffo);
	if (pffo->flags != NULL)
	{
		if (pffo->sign == '+' && ft_strchr(pffo->flags, '+'))
			pf_add_positive_diu(pffo);
		if (pffo->sign == '+' && ft_strchr(pffo->flags, ' ')
				&& !(ft_strchr(pffo->flags, '+')))
			pf_add_space_diu(pffo);
	}
}
