/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 12:40:04 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:52:35 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_lst		*pf_create_link(char *input)
{
	t_lst		*ret;

	ret = (t_lst*)malloc(sizeof(t_lst));
	if (ret)
	{
		ret->data = ft_strdup_f(input);
		ret->ret = 0;
		ret->mfw_n = 0;
		ret->next = NULL;
	}
	return (ret);
}

void		pf_put_in_lst(t_info *info, char *input)
{
	if (info->lst_first->data == NULL)
	{
		info->lst->data = ft_strdup_f(input);
		info->lst_first = info->lst;
	}
	else
	{
		while (info->lst->next)
			info->lst = info->lst->next;
		info->lst->next = pf_create_link(input);
		info->lst = info->lst->next;
	}
}

static void	join_process(t_info *info, char **str, unsigned long long *miaou)
{
	t_lst		*tmp;
	int			i;

	i = 0;
	tmp = NULL;
	while (info->lst)
	{
		if (*str == NULL)
			*str = pf_strsub_spe(info, info->lst->ret, 0);
		else if (!(!info->lst->data || (!ft_strlen(info->lst->data) \
						&& !info->lst->mfw_n)) || info->lst->ret)
		{
			miaou[0] = info->ret;
			*str = pf_strjoin_spe(*str, info, i, 0);
			miaou[0] == info->ret ? *miaou = info->ret : free(info->lst->data);
		}
		i = info->lst->ret;
		tmp = info->lst;
		info->lst = info->lst->next;
		ft_memdel((void **)&tmp);
	}
}

int			pf_print_list(t_info *info)
{
	unsigned long long		miaou;
	char					*str;

	miaou = 0;
	info->lst = info->lst_first;
	str = NULL;
	if (!info->lst->data)
		return (0);
	else if (!info->lst_first)
	{
		ft_putstr("0\n");
		return (0);
	}
	join_process(info, &str, &miaou);
	ft_memdel((void **)&info->lst);
	miaou = info->ret;
	if (info->ret > 0)
		write(1, str, info->ret);
	ft_memdel((void **)&str);
	ft_memdel((void **)&info[0]);
	return (miaou);
}
