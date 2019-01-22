/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:14:18 by erli              #+#    #+#             */
/*   Updated: 2019/01/22 09:12:23 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_sort_tab_3(char **tab, int (*f)(char *, char *))
{
	if (f(tab[0], tab[1]) < 0 && f(tab[0], tab[2]) < 0)
	{
		if (f(tab[2], tab[1]) < 0)
			ft_swap_str(tab + 1, tab + 2);
	}
	else if (f(tab[1], tab[0]) < 0 && f(tab[1], tab[2]) < 0)
	{
		if (f(tab[0], tab[2]) > 0)
		{
			ft_swap_str(tab, tab + 1);
			ft_swap_str(tab + 1, tab + 2);
		}
		else
			ft_swap_str(tab + 1, tab);
	}
	else if (f(tab[0], tab[1]) > 0)
		ft_swap_str(tab + 2, tab);
	else
	{
		ft_swap_str(tab + 1, tab);
		ft_swap_str(tab, tab + 2);
	}
}

static	char	**ft_small_sort(char **tab, int len,
					int (*f)(char *, char *))
{
	if (len == 1)
		return (tab);
	else if (len == 2)
	{
		if (f(tab[0], tab[1]) > 0)
			ft_swap_str(tab, tab + 1);
		return (tab);
	}
	else
		ft_sort_tab_3(tab, f);
	return (tab);
}

static	char	**ft_merge(char **tab1, char **tab2, int *len,
					int (*f)(char *, char *))
{
	char	*tab3[len[0]];
	int		i;
	int		i1;
	int		i2;

	i = 0;
	while (i < len[0])
	{
		tab3[i] = tab1[i];
		i++;
	}
	i = 0;
	i1 = 0;
	i2 = 0;
	while (i < len[0] + len[1])
	{
		if (i1 == len[0])
			tab1[i++] = tab2[i2++];
		else if ((i2 == len[1]) || (f(tab3[i1], tab2[i2]) <= 0))
			tab1[i++] = tab3[i1++];
		else
			tab1[i++] = tab2[i2++];
	}
	return (tab1);
}

static	char	**ft_merge_sort(char **tab, size_t len,
					int (*f)(char *, char *))
{
	char	**tab1;
	char	**tab2;
	int		lens[2];

	if (len <= 3)
		return (ft_small_sort(tab, len, f));
	lens[0] = len / 2;
	lens[1] = len - lens[0];
	tab1 = ft_merge_sort(tab, lens[0], f);
	tab2 = ft_merge_sort(tab + lens[0], lens[1], f);
	return (ft_merge(tab1, tab2, lens, f));
}

void			ls_merge_sort(char **src, size_t len,
					int (*f)(char *, char *))
{
	char	**tab;

	if (len == 0)
		return ;
	tab = src;
	ft_merge_sort(tab, len, f);
}
