/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:30:25 by erli              #+#    #+#             */
/*   Updated: 2019/01/26 18:49:27 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static	void	ls_trim_arg(char **argv, int *len)
{
	int		i;
	int		j;
	int		old_len;

	i = 0;
	j = 0;
	old_len = *len;
while (i < old_len)
	{
		if (argv[i][0] == '\0' || argv[i][0] == 2)
		{
			if (argv[i][0] == 0)
				*len -= 1;
			while (j < old_len && (argv[j][0] == '\0' || argv[j][0] == 2))
				j++;
			if (j < old_len)
			{
				argv[i] = argv[j];
				argv[j][0] = 2;
			}
		}
		i++;
	}
}

int				ls_sort_argv(char **argv, int len)
{
	char	*dup[len];
	int		i;
	int		n_dir;

	i = 0;
	n_dir = 0;
	while (i < len)
	{
		if (argv[i][0] != '\0' && ls_file_is_dir(argv[i]))
		{
			dup[n_dir++] = argv[i];
			argv[i] = "";
		}
		i++;
	}
	ls_trim_arg(argv, &i);
	len = i + n_dir;
	n_dir = 0;
	while (i < len)
		argv[i++] = dup[n_dir++];
	return (len);
}
