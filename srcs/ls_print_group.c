/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 11:33:44 by erli              #+#    #+#             */
/*   Updated: 2019/01/26 16:41:39 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls"
#include "libft.h"
#include <prg.h>

void		ls_print_group(t_ls_data *ls_data)
{
	ft_printf("%*s ", ls_data->max_gid,
		(getgrgid((ls_data->data)[i].st_gid).gr_name);
}
