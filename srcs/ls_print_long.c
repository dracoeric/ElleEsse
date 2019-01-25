/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:37:55 by erli              #+#    #+#             */
/*   Updated: 2019/01/25 18:32:31 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void			ls_print_long(t_ls_data *ls_data)
{
	struct stat	data[1];
	int			i;
	int			path_len;

	if (ls_data->is_dir)
	{
		stat(ls_data->base_path, data);
		ft_printf("total %d\n", data->st_blocks);
	}
	i = 0;
	while (i < ls_data->count)
	{
		path_len = ft_strlen(ls_data->base_path);
		path_len += ft_strlen((ls_data->arg)[i]) + 2;
		ls_print_mode(ls_data, i, path_len);
		ft_printf("%3d erli  2018_paris  %s\n", 10, (ls_data->arg)[i]);
		i++;
	}
}
