/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:00:48 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 15:00:38 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ls_print_format(t_ls_data *ls_data)
{
	if (ls_data->count == 0)
		return ;
	if (ls_data->options & LS_OPT_L)
		ls_print_long(ls_data);
}
