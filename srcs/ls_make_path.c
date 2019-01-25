/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_make_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 09:21:44 by erli              #+#    #+#             */
/*   Updated: 2019/01/25 18:35:50 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

char		*ls_make_path(char *base_path, char *file, char *path)
{
	int base_len;
	int	tot_len;

	base_len = ft_strlen(base_path);
	tot_len = base_len + ft_strlen(file) + 1;
	ft_strcpy(path, base_path);
	path[base_len] = '/';
	ft_strcpy(path + base_len + 1, file);
	path[tot_len] = '\0';
	return (path);
}
