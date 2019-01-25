/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:37:55 by erli              #+#    #+#             */
/*   Updated: 2019/01/25 19:55:00 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void			ls_print_long(t_ls_data *ls_data)
{
	int			i;
	int			path_len;

	if (ls_data->is_dir)
		ls_print_total_blocks_size(ls_data);
	i = 0;
	while (i < ls_data->count)
	{
		path_len = ft_strlen(ls_data->base_path);
		path_len += ft_strlen((ls_data->arg)[i]) + 2;
		ls_print_mode(ls_data, i, path_len);
		ls_print_links(ls_data, i);
		ls_print_owner(ls_data, i);
		ls_print_group(ls_data, i);
		ls_print_size(ls_data, i);
		ls_print_date(ls_data, i);
		ls_print_file_name(ls_data_i);
		ft_printf("%3d erli  2018_paris  %s\n", 10, (ls_data->arg)[i]);
		i++;
	}
}
