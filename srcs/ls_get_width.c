/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:38:33 by erli              #+#    #+#             */
/*   Updated: 2019/01/28 09:05:45 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned int	ls_get_width(unsigned int nb)
{
	int width;
	int pow;

	pow = 1;
	width = 1;
	while (nb / pow >= 10)
	{
		pow *= 10;
		width++;
	}
	return (width);
}
