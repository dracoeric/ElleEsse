/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_dev_major_minor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 11:36:06 by erli              #+#    #+#             */
/*   Updated: 2019/01/27 12:58:49 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_get_dev_major_minor(struct stat *data, unsigned int *tab)
{
	tab[0] = (data->st_rdev >> 8);
	tab[1] = (data->st_rdev & 255);
}
