/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_owner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:49:50 by erli              #+#    #+#             */
/*   Updated: 2019/01/28 08:59:01 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <unistd.h>
#include <pwd.h>

void				ls_print_owner(t_ls_data *ls_data, int i)
{
	ft_printf("%-*s  ", ls_data->max_uid,
		(getpwuid((ls_data->data)[i].st_uid))->pw_name);
}
