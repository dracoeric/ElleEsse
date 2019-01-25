/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:17:11 by erli              #+#    #+#             */
/*   Updated: 2019/01/25 18:52:01 by erli             ###   ########.fr       */
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

static	void	ls_get_stat_data_i(t_ls_data *ls_data, int i, int path_len)
{
	char path[path_len];

	if (ls_data->is_dir == 0)
		lstat(ls_data->base_path, (ls_data->data) + i);
	else
		lstat(ls_make_path(ls_data->base_path, (ls_data->arg)[i], path),
		(ls_data->data) + i);
}

static	void	ls_get_stat_data(t_ls_data *ls_data)
{
	int i;
	int	path_len;

	i = 0;
	while (i < ls_data->count)
	{
		path_len = ft_strlen(ls_data->base_path);
		path_len += ft_strlen((ls_data->arg)[i]) + 2;
		ls_get_stat_data_i(ls_data, i, path_len);
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
	ls_data->arg = arg;
	ls_data->base_path = str;
	ls_data->options = options;
	ls_data->count = count;
	ls_data->data = data;
	ls_get_stat_data(ls_data);
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
