/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:37:55 by erli              #+#    #+#             */
/*   Updated: 2019/01/25 09:51:55 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void			ls_print_long(char *str, char **arg, int len, int options)
{
	struct stat	data[1];
	int			i;

	stat(".", data);
	i = 0;
	ft_printf("total %d\n", data->st_blocks);
	ft_printf("arg = %ts\n", arg, len);
	while (i < len)
	{
		ls_print_mode(str, arg[i], options);
		ft_printf("%3d erli  2018_paris  %s\n", 10, arg[i]);
		i++;
	}
}
