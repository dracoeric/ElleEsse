/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:17:11 by erli              #+#    #+#             */
/*   Updated: 2019/01/22 16:34:40 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void		ls_list(char *str, int options)
{
	DIR				*dirp;
	struct dirent	*dir;
	struct stat		data[1];
	
	stat(str, data);
	if (S_ISDIR(data->st_mode))
		dirp = opendir(str);
	else
		return ;
	while ((dir = readdir(dirp)))
	{
		ft_printf(dir->d_name);
		write(1, "\n", 1);
	}
	if (options == 0)
		ft_printf("ole\n");
}
