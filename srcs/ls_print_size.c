/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:45:57 by erli              #+#    #+#             */
/*   Updated: 2019/01/28 09:04:56 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void			ls_print_size(t_ls_data *ls_data, int i)
{
	int				width;
	unsigned int	tab[2];

	width = ls_get_width(ls_data->max_size);
	if (ls_data->max_minor != 0)
	{
		if (S_ISBLK((ls_data->data)[i].st_mode)
			|| S_ISCHR((ls_data->data)[i].st_mode))
		{
			ls_get_dev_major_minor((ls_data->data) + i, tab);
			ft_printf("%*d, ", width, tab[0]);
			width = ls_get_width(ls_data->max_minor);
			ft_printf("%*d ", width, tab[1]);
		}
		else
		{
			width += ls_get_width(ls_data->max_minor) + 2;
			ft_printf("%*d ", width, (ls_data->data)[i].st_size);
		}
	}
	else
		ft_printf("%*d ", width, (ls_data->data)[i].st_size);
}
