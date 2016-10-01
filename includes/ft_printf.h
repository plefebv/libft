/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 00:48:33 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:57:49 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct				s_retlist
{
	char					*data;
	unsigned long long		ret;
	unsigned long long		mfw_n;
	struct s_retlist		*next;
}							t_lst;

typedef struct				s_info
{
	char					*flags;
	int						minfield;
	int						star_minfield;
	int						true_precision;
	int						precision;
	int						star_precision;
	char					*length;
	char					letter;
	int						stars;
	unsigned long long		ret;
	int						ret_tmp;
	int						ret_c;
	char					sign;
	t_lst					*lst;
	t_lst					*lst_first;
}							t_info;

char						*pf_itoa_ll(long long n, t_info *info);
char						*pf_itoa_ull(unsigned long long n);
char						*pf_space_strig(int size, t_info *info);
char						*pf_strsub_spe(t_info *info, int add,\
		unsigned long long i);
char						*pf_strjoin_spe(char *str, t_info *info,\
		int add, int tmp);
char						*pf_strjoin_c_null(char *s1, t_info *info,\
		unsigned long long mfw);


int							ft_printf(const char *fmt, ...);
int							pf_isletter(char c);
int							pf_print_list(t_info *info);
int							pf_dio(t_info *info);
int							pf_size_nbr(char *s);
int							pf_isupper0(char c);
int							pf_nbrlen_str(char *s);

void						pf_init_strct(t_info *info);
void						pf_epur_fmt(t_info *info, const char *fmt, int *i);
void						pf_put_in_lst(t_info *info, char *input);
//void						pf_check_flag(const char *fmt, int *i, char *dest);
void						pf_parse_arg(const char *fmt, int *i, t_info *info,\
		va_list ap);
void						pf_clean_info(t_info *info);
void						pf_stars(int value, t_info *info, int *i,\
		const char *fmt);
void						pf_work(void *ap, t_info *info);
void						pf_dioux(void *ap, t_info *info);
void						pf_di_length(void *ap, t_info *info);
void						pf_dioux_length(void *ap, t_info *info);
void						pf_u(void *ap, t_info *info);
void						pf_di(void *ap, t_info *info);
void						pf_add_sign_diu(t_info *info);
void						pf_add_positive_diu(t_info *info);
void						pf_add_negative_di(t_info *info);
void						pf_add_space_diu(t_info *info);
void						pf_put_letter(const char *fmt, int *i,\
		t_info *info);
void						pf_precision_dioux(void *ap, t_info *info);
void						pf_add_precision_dioux(t_info *info, int add);
void						pf_add_char(char **s, int add, char c);
void						pf_minfield(t_info *info);
void						pf_add_minfield_l(t_info *info, int add, char c);
void						pf_add_minfield_r(t_info *info, int add, char c);
void						pf_sc(void *ap, t_info *info);
void						pf_put_wc(wchar_t ap, t_info *info);
void						pf_put_char(char ap, t_info *info);
void						pf_put_ws(void *ap, t_info *info);
void						pf_convert_wchar(wchar_t ap, t_info *info);
void						pf_percentage(t_info *info);
void						pf_treat_data(t_info *info);
void						pf_hex(void *ap, t_info *info);
void						pf_octal(void *ap, t_info *info);
void						pf_precision_s(t_info *info);
void						pf_precision_p(void *ap, t_info *info);
void						pf_put_mfw2(t_info *info);
void						pf_hex2(void *ap, t_info *info);
void						pf_char_minfield(t_info *info, int left);

t_lst						*pf_create_list(const char *fmt);
t_lst						*pf_create_link(char *input);

#endif
