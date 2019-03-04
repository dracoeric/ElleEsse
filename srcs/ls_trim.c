/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:39:28 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 15:10:05 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_trim(char **arg, int *len, int options)
{
	int i;
	int j;
	int	old_len;

	i = 0;
	j = 0;
	old_len = *len;
	if (!(options & LS_OPT_A))
	{
		while (i < old_len)
		{
			if (arg[i][0] == '.' || arg[i][0] == 0)
			{
				*len -= (arg[i][0] == '.' ? 1 : 0);
				while (j < old_len && arg[j][0] == '.')
					j++;
				if (j < old_len)
				{
					arg[i] = arg[j];
					arg[j++] = "";
				}
			}
			i++;
		}
	}
}
