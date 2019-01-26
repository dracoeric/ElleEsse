/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:00:48 by erli              #+#    #+#             */
/*   Updated: 2019/01/26 19:07:24 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>

void			ls_print_format(t_ls_data *ls_data)
{
	if (ls_data->count == 0)
		return ;
	if (LS_OPT_L(ls_data->options))
		ls_print_long(ls_data);
}
