/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:17:11 by erli              #+#    #+#             */
/*   Updated: 2019/01/26 19:28:55 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <dirent.h>
#include <grp.h>
#include <pwd.h>

static	int		ls_parse_arg(t_ls_data *ls_data, char *str, char **arg,
					int *count)
{
	struct dirent	*dir;
	DIR				*dirp;
	int				i;

	if (!(dirp = opendir(str)))
	{
		*arg = str;
		ls_data->dirp = NULL;
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
		ls_data->dirp = dirp;
		return (1);
	}
}

static	void	ls_get_stat_data_i(t_ls_data *ls_data, int i, int path_len)
{
	char			path[path_len];
	unsigned int	len_uid;
	unsigned int	len_gid;

	if (ls_data->is_dir == 0)
		lstat(ls_data->base_path, (ls_data->data) + i);
	else
		lstat(ls_make_path(ls_data->base_path, (ls_data->arg)[i], path),
		(ls_data->data) + i);
	if (LS_OPT_L(ls_data->options) || LS_OPT_LG(ls_data->options))
	{
		len_uid = ft_strlen(getpwuid((ls_data->data)[i].st_uid)->pw_name);
		len_gid = ft_strlen(getgrgid((ls_data->data)[i].st_gid)->gr_name);
		if ((unsigned int)(ls_data->data)[i].st_nlink > ls_data->max_link)
			ls_data->max_link = (ls_data->data)[i].st_nlink;
		if ((unsigned int)(ls_data->data)[i].st_size > ls_data->max_size)
			ls_data->max_size = (ls_data->data)[i].st_size;
		if (len_uid > ls_data->max_uid)
			ls_data->max_uid = len_uid;
		if (len_gid > ls_data->max_gid)
			ls_data->max_gid = len_gid;
	}	
}

static	void	ls_get_stat_data(t_ls_data *ls_data)
{
	int i;
	int	path_len;

	ls_data->max_link = 0;
	ls_data->max_size = 0;
	ls_data->max_uid = 0;
	ls_data->max_gid = 0;
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

	ls_data->is_dir = ls_parse_arg(ls_data, str, arg, &count);
	ft_printf("arg avant sort %ts\n", arg, count);
	ls_sort(arg, count, options);
	ft_printf("arg apres sort %ts\n", arg, count);
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
	if (ls_data->dirp != NULL)
		closedir(ls_data->dirp);
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
	if (dirp != NULL)
		closedir(dirp);
}
