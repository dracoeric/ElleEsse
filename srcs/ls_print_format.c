/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:00:48 by erli              #+#    #+#             */
/*   Updated: 2019/01/25 09:19:23 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>

/*
static	void	ls_print_long(char **arg, int len, int options)
{
	struct stat	data[1];

	stat(".", data);
	ft_printf("total %d\n", data->st_blocks);	

}

static	void	ls_print_default(char **arg, int len, int options)
{
	struct stat	data[1];

	stat(".", data);
	ft_printf("total %d\n", data->st_blocks);	

}
*/
void			ls_print_format(char *str, char **arg, int len, int options)
{
	if (len == 0)
		return ;
	if (LS_OPT_L(options))
		ls_print_long(str, arg, len, options);
/*	else if (LS_OPT_L(options))
		ls_print_long(arg, len, options);
	else
		ls_print_default(arg, len, options);
*/
}
