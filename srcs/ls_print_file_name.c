/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:57:06 by erli              #+#    #+#             */
/*   Updated: 2019/01/26 17:13:10 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void				ls_print_file_name(t_ls_data *ls_data, int i)
{
	write(1, (ls_data->arg)[i], ft_strlen((ls_data->arg)[i]));
	write(1, "\n", 1);
}
