/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:19:20 by erli              #+#    #+#             */
/*   Updated: 2019/01/25 18:42:07 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/acl.h>
#include <sys/types.h>
#include <sys/xattr.h>

static	void	ls_read_file_type(struct stat *data, char *str)
{
	if (S_ISFIFO(data->st_mode))
		str[0] = 'p';
	else if (S_ISCHR(data->st_mode))
		str[0] = 'c';
	else if (S_ISDIR(data->st_mode))
		str[0] = 'd';
	else if (S_ISBLK(data->st_mode))
		str[0] = 'b';
	else if (S_ISLNK(data->st_mode))
		str[0] = 'l';
	else if (S_ISSOCK(data->st_mode))
		str[0] = 's';
}

static	void	ls_read_rights(struct stat *data, char *str)
{
	if ((data->st_mode & S_IRUSR) == S_IRUSR)
		str[1] = 'r';
	if ((data->st_mode & S_IWUSR) == S_IWUSR)
		str[2] = 'w';
	if ((data->st_mode & S_IXUSR) == S_IXUSR)
		str[3] = ((data->st_mode & S_ISUID) == S_ISUID ? 's' : 'x');
	else if ((data->st_mode & S_ISUID) == S_ISUID)
		str[3] = 'S';
	if ((data->st_mode & S_IRGRP) == S_IRGRP)
		str[4] = 'r';
	if ((data->st_mode & S_IWGRP) == S_IWGRP)
		str[5] = 'w';
	if ((data->st_mode & S_IXGRP) == S_IXGRP)
		str[6] = ((data->st_mode & S_ISGID) == S_ISGID ? 's' : 'x');
	else if ((data->st_mode & S_ISGID) == S_ISGID)
		str[6] = 'S';
	if ((data->st_mode & S_IROTH) == S_IROTH)
		str[7] = 'r';
	if ((data->st_mode & S_IWOTH) == S_IWOTH)
		str[8] = 'w';
	if ((data->st_mode & S_IXOTH) == S_IXOTH)
		str[9] = 'x';
}

void			ls_print_mode(t_ls_data *ls_data, int i, int path_len)
{
	acl_t		acl;
	ssize_t		num_attr;
	char		path[path_len];
	char		str[12];

	ft_strncpy(str, "---------- ", 11);
	ls_read_file_type((ls_data->data) + i, str);
	ls_read_rights((ls_data->data) + i, str);
	acl = NULL;
	acl = acl_get_file(ls_make_path(ls_data->base_path, (ls_data->arg)[i],
				path), ACL_TYPE_EXTENDED);
	num_attr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (acl != NULL)
	{
		str[10] = '+';
		acl_free(acl);
	}
	else if (num_attr > 0 && ls_data->options >= 0)
		str[10] = '@';
	write(1, str, 11);
}
