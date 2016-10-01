/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:51:03 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:55:33 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*pf_strsub_spe(t_info *info, int add, unsigned long long i)
{
	char	*ret;

	i = 0;
	info->ret = ft_strlen(info->lst->data) + add + info->lst->mfw_n;
	ret = (char *)malloc(sizeof(char) * (info->ret + 1));
	if (ret)
	{
		while (i < info->ret)
		{
			ret[i] = info->lst->data[i];
			i++;
		}
		ret[i] = '\0';
		free(info->lst->data);
		return (ret);
	}
	else
		return (NULL);
}

static char	*part_one(t_info *info, char **str, int i)
{
	char	*ret;

	ret = NULL;
	if (i == 1)
	{
		if (*str)
			ret = pf_strjoin_c_null(*str, info, info->lst->mfw_n);
		info->ret += 1 + info->lst->mfw_n;
		info->lst->ret = info->lst->mfw_n == 0 ? 1 : 0;
		ft_memdel((void **)&(*str));
		return (ret);
	}
	if (i == 2)
	{
		if (*str)
			ret = pf_strjoin_c_null(*str, info, 0);
		info->ret += (1);
		info->lst->ret = 1;
		ft_memdel((void **)&(*str));
		return (ret);
	}
	return (NULL);
}

char		*pf_strjoin_spe(char *str, t_info *info, int add, int tmp)
{
	char					*ret;
	unsigned long long		i;
	unsigned long long		j;

	i = -1;
	j = 0;
	ret = NULL;
	tmp = ft_strlen(info->lst->data);
	if (info->lst->ret == 1 && info->lst->mfw_n)
		return (part_one(info, &str, 1));
	else if (info->lst->ret == 1 && !info->lst->mfw_n)
		return (part_one(info, &str, 2));
	else if (tmp > 0 && (info->ret += tmp))
	{
		if ((ret = (char *)malloc(sizeof(char) * (info->ret + 1))))
		{
			while (++i < info->ret - tmp - add)
				ret[i] = str[i];
			while (i + add < info->ret)
				ret[i++ + add] = info->lst->data[j++];
		}
		ft_memdel((void **)&str);
		return (ret);
	}
	return (str);
}
