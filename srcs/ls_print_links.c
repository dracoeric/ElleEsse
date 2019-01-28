/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:59:07 by erli              #+#    #+#             */
/*   Updated: 2019/01/28 08:54:14 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void			ls_print_links(t_ls_data *ls_data, int i)
{
	int width;

	width = ls_get_width(ls_data->max_link) + 1;
	ft_printf("%*d ", width, (ls_data->data)[i].st_nlink);
}
