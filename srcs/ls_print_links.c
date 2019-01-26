/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:59:07 by erli              #+#    #+#             */
/*   Updated: 2019/01/26 11:26:17 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls"
#include "libft.h"

void			ls_print_links(t_ls_data *ls_data, int i)
{
	int width;

	width = ls_get_width(ls_data->max_links);
	ft_printf("%*d ", width, ls_data->data)[i].st_nlinks);
}
