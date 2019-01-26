/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:45:57 by erli              #+#    #+#             */
/*   Updated: 2019/01/26 19:42:02 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void			ls_print_size(t_ls_data *ls_data, int i)
{
	int	width;

	width = ls_get_width(ls_data->max_size);
	ft_printf("%*d ", width, (ls_data->data)[i].st_size);
}
