/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 15:53:50 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:53:26 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*pf_strjoin_c_null(char *s1, t_info *info, unsigned long long mfw)
{
	char					*s3;
	unsigned long long		len;
	unsigned long long		i;
	unsigned long long		j;
	unsigned long long		tmp;

	i = -1;
	j = 0;
	tmp = ft_strlen(info->lst->data);
	info->ret += tmp;
	len = info->ret + mfw + 1;
	s3 = (char *)malloc(sizeof(*s3) * (len + 300 + 1));
	if (s3)
	{
		while (s1 && ++i < info->ret - tmp)
			s3[i] = s1[i];
		while (s1 && i < info->ret + mfw + 1)
			s3[i++] = info->lst->data[j++];
		s3[i] = '\0';
		return (s3);
	}
	else
		return (NULL);
}
