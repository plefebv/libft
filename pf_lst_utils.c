/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 12:40:04 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 15:52:33 by plefebvr         ###   ########.fr       */
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

void		pf_put_in_lst(t_pffo *pffo, char *input)
{
	if (pffo->lst_first->data == NULL)
	{
		pffo->lst->data = ft_strdup_f(input);
		pffo->lst_first = pffo->lst;
	}
	else
	{
		while (pffo->lst->next)
			pffo->lst = pffo->lst->next;
		pffo->lst->next = pf_create_link(input);
		pffo->lst = pffo->lst->next;
	}
}

static void	join_process(t_pffo *pffo, char **str, unsigned long long *miaou)
{
	t_lst		*tmp;
	int			i;

	i = 0;
	tmp = NULL;
	while (pffo->lst)
	{
		if (*str == NULL)
			*str = pf_strsub_spe(pffo, pffo->lst->ret, 0);
		else if (!(!pffo->lst->data || (!ft_strlen(pffo->lst->data) \
						&& !pffo->lst->mfw_n)) || pffo->lst->ret)
		{
			miaou[0] = pffo->ret;
			*str = pf_strjoin_spe(*str, pffo, i, 0);
			miaou[0] == pffo->ret ? *miaou = pffo->ret : free(pffo->lst->data);
		}
		i = pffo->lst->ret;
		tmp = pffo->lst;
		pffo->lst = pffo->lst->next;
		ft_memdel((void **)&tmp);
	}
}

int			pf_print_list(t_pffo *pffo)
{
	unsigned long long		miaou;
	char					*str;

	miaou = 0;
	pffo->lst = pffo->lst_first;
	str = NULL;
	if (!pffo->lst->data)
		return (0);
	else if (!pffo->lst_first)
	{
		ft_putstr("0\n");
		return (0);
	}
	join_process(pffo, &str, &miaou);
	ft_memdel((void **)&pffo->lst);
	miaou = pffo->ret;
	if (pffo->ret > 0)
		write(1, str, pffo->ret);
	ft_memdel((void **)&str);
	ft_memdel((void **)&pffo[0]);
	return (miaou);
}
