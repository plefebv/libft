/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 15:16:17 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:54:05 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void				pf_put_mfw2(t_info *info)
{
	if (info->minfield < 0)
	{
		info->minfield = -(info->minfield);
		if (info->flags)
			info->flags = ft_strjoin_f1(info->flags, "-");
		else
			info->flags = ft_strdup("-");
	}
}

static void			percentage(t_info *info, int *i, char c)
{
	(*i)++;
	info->letter = c;
	if (c == '%')
	{
		*i += 1;
		if (info->minfield)
			pf_put_in_lst(&info[0], ft_strdup(""));
	}
	else
		(*i)++;
}

static void				pf_special_letter2(t_info *info, char c)
{
	if (c == 'S')
	{
		info->letter = 's';
		if (info->length != NULL)
			free(info->length);
		info->length = ft_strdup("l");
	}
	if (c == 'C')
	{
		info->letter = 'c';
		if (info->length != NULL)
			free(info->length);
		info->length = ft_strdup("l");
	}
}

static void				pf_special_letter(t_info *info, char c)
{
	if (c == 'D')
	{
		info->letter = 'd';
		if (info->length != NULL)
			free(info->length);
		info->length = ft_strdup("l");
	}
	if (c == 'O')
	{
		info->letter = 'o';
		if (info->length != NULL)
			free(info->length);
		info->length = ft_strdup("l");
	}
	if (c == 'U')
	{
		info->letter = 'u';
		if (info->length != NULL)
			free(info->length);
		info->length = ft_strdup("l");
	}
	pf_special_letter2(info, c);
}

void				pf_put_letter(const char *fmt, int *i, t_info *info)
{
	char	c;

	c = fmt[*i + 1];
	if (c == '+' && (c = fmt[++(*i) + 1]))
		info->flags = info->flags ? ft_strjoin_f1(info->flags, "+")
			: ft_strdup("+");
	if (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X'
			|| c == 'c' || c == '%')
		percentage(info, i, c);
	else if (c == 'D' || c == 'O' || c == 'U' || c == 'S' || c == 'C')
	{
		pf_special_letter(info, c);
		*i += 2;
	}
	else
	{
		info->letter = c;
		*i += fmt[*i + 1] == '\0' ? 1 : 2;
	}
}
