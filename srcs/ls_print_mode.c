/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:19:20 by erli              #+#    #+#             */
/*   Updated: 2019/01/23 17:29:06 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/acl.h>
#include <sys/types.h>

static	void	ls_print_file_type(struct stat *data)
{
	if (S_ISFIFO(data->st_mode))
		write(1, "p", 1);
	else if (S_ISCHR(data->st_mode))
		write(1, "c", 1);
	else if (S_ISDIR(data->st_mode))
		write(1, "d", 1);
	else if (S_ISBLK(data->st_mode))
		write(1, "b", 1);
	else if (S_ISREG(data->st_mode))
		write(1, "-", 1);
	else if (S_ISLNK(data->st_mode))
		write(1, "l", 1);
	else if (S_ISSOCK(data->st_mode))
		write(1, "s", 1);
}

static	void	ls_print_rights(struct stat *data)
{
	char str[9];

	ft_strcpy(str, "--------");
	if ((data->st_mode & S_IRUSR) == S_IRUSR)
		str[0] = 'r';
	if ((data->st_mode & S_IWUSR) == S_IWUSR)
		str[1] = 'w';
	if ((data->st_mode & S_IXUSR) == S_IXUSR)
		str[2] = ((data->st_mode & S_ISUID) == S_ISUID ? 's' : 'x');
	else if ((data->st_mode & S_ISUID) == S_ISUID)
		str[2] = 'S';
	if ((data->st_mode & S_IRGRP) == S_IRGRP)
		str[3] = 'r';
	if ((data->st_mode & S_IWGRP) == S_IWGRP)
		str[4] = 'w';
	if ((data->st_mode & S_IXGRP) == S_IXGRP)
		str[5] = ((data->st_mode & S_ISGID) == S_ISGID ? 's' : 'x');
	else if ((data->st_mode & S_ISGID) == S_ISGID)
		str[5] = 'S';	
	if ((data->st_mode & S_IROTH) == S_IROTH)
		str[6] = 'r';
	if ((data->st_mode & S_IWOTH) == S_IWOTH)
		str[7] = 'w';
	write(1, str, 8);
}

void			ls_print_mode(char *file, int options)
{
	struct stat data[1];
	acl_t		acl;
	acl_entry_t	*entry;

	stat(file, data);
	ls_print_file_type(data);
	ls_print_rights(data);
	write(1, ((data->st_mode & S_IXOTH) == S_IXOTH ? "x" : "-"), 1);
	acl = acl_get_file(file, ACL_TYPE_ACCESS);
	if (LS_OPT_E(options))
	{
		if (acl == NULL)
			perror(NULL);
		else
		{
			entry = NULL;
			if (acl_get_entry(acl, 0, entry) == 0)
				ft_printf("ici\n");
		}
	}
}
