/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 18:04:25 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:53:52 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void			pf_put_flag(const char *fmt, int *i, t_info *info)
{
	int		tmp;

	tmp = *i;
	while (fmt[*i + 1] == '-' || fmt[*i + 1] == '+' || fmt[*i + 1] == ' '
			|| fmt[*i + 1] == '#' || fmt[*i + 1] == '0')
		*i += 1;
	if (*i > tmp)
		info->flags = ft_strsub(fmt, tmp + 1, *i - tmp);
	else
		info->flags = NULL;
}

static void			pf_put_mfw(const char *fmt, int *i, t_info *info, va_list ap)
{
	int		tmp;
	char	*str;

	tmp = *i;
	str = NULL;
	while ((ft_isdigit(fmt[*i + 1])))
		(*i)++;
	if (fmt[*i + 1] == '*')
	{
		if (fmt[*i + 1] == '*' && !(fmt[*i + 2] && ft_isdigit(fmt[*i + 2])))
			info->minfield = va_arg(ap, int);
		else if (fmt[*i + 1] == '*')
			va_arg(ap, int);
		(*i)++;
		tmp = *i;
		while ((ft_isdigit(fmt[*i + 1])))
			(*i)++;
	}
	if (*i > tmp)
	{
		str = ft_strsub(fmt, tmp + 1, *i - tmp);
		info->minfield = ft_atoi(str);
		ft_memdel((void **)&str);
	}
	pf_put_mfw2(info);
}

static void			pf_put_precision(const char *fmt, int *i, t_info *info, va_list ap)
{
	int		tmp;
	char	*str;

	tmp = *i;
	str = NULL;
	if (fmt[*i + 1] == '.')
	{
		info->true_precision = 1;
		(*i)++;
		while ((ft_isdigit(fmt[*i + 1])))
			(*i)++;
		if (fmt[*i + 1] == '*')
		{
			info->precision = va_arg(ap, int);
			(*i)++;
		}
		else if (tmp < *i)
		{
			str = ft_strsub(fmt, tmp + 2, *i - tmp - 1);
			info->precision = ft_atoi(str);
			ft_memdel((void**)&str);
		}
	}
}

static void			pf_put_length(const char *fmt, int *i, t_info *info)
{
	int tmp;

	tmp = *i;
	if (fmt[*i + 1] == 'h' && fmt[*i + 2] == 'h')
	{
		*i += 2;
		info->length = ft_strdup("hh");
	}
	if (fmt[*i + 1] == 'l' && fmt[*i + 2] == 'l')
	{
		*i += 2;
		info->length = ft_strdup("ll");
	}
	if (fmt[*i + 1] == 'h' || fmt[*i + 1] == 'l' || fmt[*i + 1] == 'j'
			|| fmt[*i + 1] == 'z')
	{
		(*i)++;
		info->length = ft_strsub(&fmt[*i], 0, 1);
	}
	while (fmt[*i + 1] == 'h' || fmt[*i + 1] == 'l' ||
			fmt[*i + 1] == 'j' || fmt[*i + 1] == 'z')
		(*i)++;
}

void				pf_parse_arg(const char *fmt, int *i, t_info *info, va_list ap)
{
	pf_put_flag(fmt, i, info);
	pf_put_mfw(fmt, i, info, ap);
	pf_put_precision(fmt, i, info, ap);
	pf_put_length(fmt, i, info);
	pf_put_letter(fmt, i, info);
}
