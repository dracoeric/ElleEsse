/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:17:11 by erli              #+#    #+#             */
/*   Updated: 2019/01/25 18:41:10 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <dirent.h>

static	int		ls_parse_arg(char *str, char **arg, int *count)
{
	struct dirent	*dir;
	DIR				*dirp;
	int				i;

	if (!(dirp = opendir(str)))
	{
		*arg = str;
		return (0);
	}
	else
	{
		i = 0;
		while ((dir = readdir(dirp)))
		{
			arg[i] = dir->d_name;
			i++;
		}
		if (i == 0)
			*count = 0;
		return (1);
	}
}

static	void	ls_get_stat_data_i(char *str, char *arg,
						struct stat *data, int i)
{
	char path[ft_strlen(str) + ft_strlen(arg) + 2];

	lstat(ls_make_path(str, arg, path), data + i);
}

static	void	ls_get_stat_data(char *str, char **arg, int len,
						struct stat *data)
{
	int i;

	i = 0;
	while (i < len)
	{
		ls_get_stat_data_i(str, arg[i], data, i);
		i++;
	}
}

static	void	ls_print_list(char *str, int count, int options)
{
	char			*arg[count];
	struct stat		data[count];
	t_ls_data		ls_data[1];

	ls_data->is_dir = ls_parse_arg(str, arg, &count);
	ls_sort(arg, count, options);
	if (ls_data->is_dir == 1)
		ls_trim(arg, &count, options);
	ls_get_stat_data(str, arg, count, data);
	ls_data->arg = arg;
	ls_data->base_path = str;
	ls_data->options = options;
	ls_data->data = data;
	ls_data->count = count;
	if (LS_OPT_MULT(options) && ls_data->is_dir == 1)
		ft_printf("%s:\n", str);
	ls_print_format(ls_data);
}

void			ls_list(char *str, int options)
{
	DIR				*dirp;
	struct dirent	*dir;
	int				count;

	count = 1;
	dirp = opendir(str);
	if (dirp != NULL)
		count = 0;
	while (dirp != NULL && (dir = readdir(dirp)))
		count++;
	ls_print_list(str, (count == 0 ? 1 : count), options);
}
