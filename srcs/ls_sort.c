/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 10:51:32 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 15:01:34 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>

static	int		ls_sort_acces_time(char *a, char *b)
{
	struct stat data_a[1];
	struct stat data_b[1];

	stat(a, data_a);
	stat(b, data_b);
/*	return (data_a->st_atim.tv_sec - data_b->st_atim.tv_sec);*/
	return (data_a->st_atimespec.tv_sec - data_b->st_atimespec.tv_sec);
}

static	int		ls_sort_mod_time(char *a, char *b)
{
	struct stat data_a[1];
	struct stat data_b[1];

	stat(a, data_a);
	stat(b, data_b);
/*	return (data_a->st_atim.tv_sec - data_b->st_atim.tv_sec);*/
	return (data_a->st_mtimespec.tv_sec - data_b->st_mtimespec.tv_sec);
}

static	int		ls_sort_lexi(char *a, char *b)
{
	int i;

	i = 0;
	while (a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}

static	void	ls_reverse(char **arg, int len)
{
	int i;

	i = 0;
	while (i < len / 2)
	{
		ft_swap_str(arg + i, arg + (len - i - 1));
		i++;
	}
}

void			ls_sort(char **arg, int len, int options)
{
	if (len == 0)
		return ;
	if (options & LS_OPT_F)
		return ;
	if (options & LS_OPT_T && options & LS_OPT_U)
		ls_merge_sort(arg, len, &ls_sort_acces_time);
	else if (options & LS_OPT_T)
		ls_merge_sort(arg, len, &ls_sort_mod_time);
	else
		ls_merge_sort(arg, len, &ls_sort_lexi);
	if (options & LS_OPT_LR)
		ls_reverse(arg, len);
}
