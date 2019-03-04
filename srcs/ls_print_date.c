/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_date.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:53:49 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 15:00:15 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <time.h>

static void		ls_print_date_year(char *full_time)
{
	full_time[11] = '\0';
	full_time[24] = '\0';
	ft_printf("%s", full_time + 4);
	ft_printf("%s ", full_time + 19);
}

static	void	ls_print_date_full(char *full_time)
{
	full_time[16] = '\0';
	ft_printf("%s ", full_time + 4);
	}

void			ls_print_date(t_ls_data *ls_data, int i)
{
	time_t	current[1];
	int		file_time;
	int		time_diff;
	char	*full_time;

	time(current);
	if (ls_data->options & LS_OPT_U)
	{
/*		full_time = ctime(&(ls_data->data)[i].st_atim.tv_sec);
 *		file_time = (ls_data->data)[i].st_atim.tv_sec;
 */		full_time = ctime(&(ls_data->data)[i].st_atimespec.tv_sec);
		file_time = (ls_data->data)[i].st_atimespec.tv_sec;
	}
	else
	{
/*		full_time = ctime(&(ls_data->data)[i].st_mtim.tv_sec);
 *		file_time = (ls_data->data)[i].st_mtim.tv_sec;
 */		full_time = ctime(&(ls_data->data)[i].st_mtimespec.tv_sec);
		file_time = (ls_data->data)[i].st_mtimespec.tv_sec;
	}
	time_diff = *current - file_time;
	if (time_diff > SIX_MONTHS || time_diff < -SIX_MONTHS)
		ls_print_date_year(full_time);
	else
		ls_print_date_full(full_time);
}
