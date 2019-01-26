/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:37:55 by erli              #+#    #+#             */
/*   Updated: 2019/01/26 19:08:09 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <unistd.h>

void			ls_print_long(t_ls_data *ls_data)
{
	int			i;
	int			path_len;

	if (ls_data->is_dir)
		ls_print_total_block_size(ls_data);
	i = 0;
	ft_printf("count = %d\n", ls_data->count);
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
 		ls_print_file_name(ls_data, i);
		i++;
	}
}
