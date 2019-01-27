/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_total_block_size.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:43:21 by erli              #+#    #+#             */
/*   Updated: 2019/01/27 17:36:42 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <unistd.h>

void	ls_print_total_block_size(t_ls_data *ls_data)
{
	int i;
	int total;

	i = 0;
	total = 0;
	while (i < ls_data->count)
	{
		ft_printf("block i = %d:\t%d\n",i, (int)(ls_data->data)[i].st_blocks);
		total = total + (int)(ls_data->data)[i].st_blocks;
		i++;
	}
	write(1, "total ", 6);
	ft_putnbr(total);
	write(1, "\n", 1);
}
