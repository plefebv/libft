/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_precision_dioux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:40:25 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 15:52:33 by plefebvr         ###   ########.fr       */
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

void		pf_add_precision_dioux(t_pffo *pffo, int add)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * (add + 1));
	if (s)
	{
		s[add] = '\0';
		pf_add_char(&s, add, '0');
		pffo->lst->data = ft_strjoin_f(s, pffo->lst->data);
	}
}

void		pf_precision_dioux(void *ap, t_pffo *pffo)
{
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(pffo->lst->data);
	if (size < pffo->precision)
		pf_add_precision_dioux(pffo, pffo->precision - size);
	if (!pffo->precision && (int)ap == 0)
	{
		while (pffo->lst->data && pffo->lst->data[i] != '\0')
		{
			if (pffo->lst->data[i] == '0')
			{
				if (pffo->minfield > 0)
					pffo->lst->data[i] = ' ';
				else
					pffo->lst->data[i] = '\0';
			}
			i++;
		}
	}
}

void		pf_precision_p(void *ap, t_pffo *pffo)
{
	int		size;
	int		i;

	i = -1;
	size = ft_strlen(pffo->lst->data);
	if (size < pffo->precision + 2)
		pf_add_precision_dioux(pffo, pffo->precision - size + 2);
	if (!pffo->precision && (int)ap == 0)
	{
		while (pffo->lst->data && pffo->lst->data[++i] != '\0')
		{
			if (pffo->lst->data[i] == '0')
			{
				if (pffo->minfield > 0)
					pffo->lst->data[i] = ' ';
				else
					pffo->lst->data[i] = '\0';
			}
		}
	}
	i = 1;
	pffo->lst->data[1] = 'x';
	while (pffo->lst->data[++i])
		if (pffo->lst->data[i] == 'x')
			pffo->lst->data[i] = '0';
}
