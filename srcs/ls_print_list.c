/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 09:46:03 by erli              #+#    #+#             */
/*   Updated: 2019/01/23 15:22:42 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <dirent.h>

void		ls_print_list(char *str, int count, int options)
{
	char			*arg[count];
	struct dirent	*dir;
	DIR				*dirp;
	int				i;

	if (!(dirp = opendir(str)))
		*arg = str;
	else
	{
		i = 0;
		while ((dir = readdir(dirp)))
		{
			arg[i] = dir->d_name;
			i++;
		}
		if (i == 0)
			count = 0;
	}
	ls_sort(arg, count, options);
	ls_trim(arg, &count, options);
	if (LS_OPT_MULT(options) && dirp != NULL)
		ft_printf("%s:\n", str);
	ls_print_format(arg, count, options);
}
