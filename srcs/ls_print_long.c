/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:37:55 by erli              #+#    #+#             */
/*   Updated: 2019/01/23 14:19:40 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>

void			ls_print_long(char **arg, int len, int options)
{
	struct stat	data[1];
	int			i;

	stat(".", data);
	i = 0;
	ft_printf("total %d\n", data->st_blocks);
	while (i < len)
	{
		ls_print_mode(arg[i], options);
		i++;
	}
}
