/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_max_major_minor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 11:43:43 by erli              #+#    #+#             */
/*   Updated: 2019/01/27 13:00:50 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_max_major_minor(t_ls_data *ls_data, int i)
{
	unsigned int	major;
	unsigned int	minor;

	major = ((ls_data->data)[i].st_rdev >> 8);
	minor = ((ls_data->data)[i].st_rdev & 255);
	if (major > ls_data->max_size)
		ls_data->max_size = major;
	if (minor > ls_data->max_minor)
		ls_data->max_minor = minor;
}
