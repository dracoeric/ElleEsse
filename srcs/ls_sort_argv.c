/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:30:25 by erli              #+#    #+#             */
/*   Updated: 2019/01/25 12:28:25 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <dirent.h>

static	void	ls_trim_arg(char **argv, int *len)
{
	int i;
	int j;
	int old_len;

	i = 0;
	j = 0;
	old_len = *len;
	while (i < old_len)
	{
		if (argv[i][0] == '\0')
		{
			*len -= 1;
			while (j < old_len && argv[j][0] != '\0')
				j++;
			if (j < old_len)
			{
				argv[i] = argv[j];
				argv[j++] = "";
			}
		}
		i++;
	}
}

void			ls_sort_argv(char **argv, int len)
{
	char	*dup[len];
	int		i;
	int		n_dir;

	i = 0;
	n_dir = 0;
	ft_printf("in sort arg = %ts, dup = %ts\n", argv, len, dup, len);
	while (i < len)
	{
		if (opendir(argv[i]))
		{
			dup[n_dir++] = argv[i];
			argv[i] = "";
		}
		i++;
	}
	ft_printf("in sort arg = %ts, dup = %ts\n", argv, len, dup, len);
	ls_trim_arg(argv, &i);
	n_dir = 0;
	while (i < len)
		argv[i++] = dup[n_dir++];
}
