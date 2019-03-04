/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:32:09 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 15:09:38 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static	void	manage_options_2(char c, int *options)
{
	char *str;

	str = "ls: illegal option -- %c\nusage: ls [-GRadfgltu@] [file ...]\n";
	if (c == 'g' && !(*options & LS_OPT_LG))
	{
		*options = (*options | LS_OPT_LG);
		*options = (*options & (unsigned int)(-1) - LS_OPT_L);
	}
	else if (c == 'd' && !(*options & LS_OPT_D))
		*options = (*options | LS_OPT_D);
	else if (c == 'G' && !(*options & LS_OPT_UG))
		*options = (*options | LS_OPT_UG);
	else
	{
		ft_printf(str, c);
		exit(0);
	}
}

static	void	manage_option(char c, int *options)
{
	if (c == 'l' && !(*options & LS_OPT_L) && !(*options & LS_OPT_LG))
		*options = (*options | LS_OPT_L);
	else if (c == 'R' && !(*options & LS_OPT_UR))
		*options = (*options | LS_OPT_UR);
	else if (c == 'a' && !(*options & LS_OPT_A) && !(*options & LS_OPT_F))
		*options = (*options | LS_OPT_A);
	else if (c == 'r' && !(*options & LS_OPT_LR))
		*options = (*options | LS_OPT_LR);
	else if (c == 't' && !(*options & LS_OPT_T) && !(*options & LS_OPT_F))
		*options = (*options | LS_OPT_T);
	else if (c == 'u' && !(*options & LS_OPT_U) && !(*options & LS_OPT_F))
		*options = (*options | LS_OPT_U);
	else if (c == 'f' && !(*options & LS_OPT_F))
	{
		*options = (*options | LS_OPT_F);
		*options &= ((unsigned int)(-1) - LS_OPT_A - LS_OPT_U - LS_OPT_T);
	}
	else
		manage_options_2(c, options);
}

static	int		get_options(int argc, char **argv, int *options)
{
	int i;
	int j;
	int loop;

	i = 1;
	loop = 1;
	while (i < argc && argv[i][0] == '-' && loop == 1)
	{
		if (argv[i][1] != '\0')
		{
			j = 1;
			while (argv[i][j] != '\0')
				manage_option(argv[i][j++], options);
			i++;
		}
		else
			loop = 0;
	}
	return (i - 1);
}

static	void	check_arg(int argc, char **argv)
{
	int			i;
	struct stat	data[1];

	i = 1;
	while (i < argc)
	{
		if (stat(argv[i], data) != 0)
		{
			ft_printf("ls: %s: ", argv[i]);
			perror(NULL);
			argv[i][0] = 0;
		}
		i++;
	}
}

int				main(int argc, char **argv)
{
	int options;
	int offset;
	int i;

	i = 0;
	options = 0;
	offset = get_options(argc, argv, &options);
	check_arg(argc - offset, argv + offset);
	if (argc - offset > 2)
		options += 4096;
	if (argc - offset == 1)
		ls_list(".", options);
	else
	{
		ls_sort(argv + offset + 1, argc - offset - 1, options);
		argc = ls_sort_argv(argv + (offset + 1), argc - offset - 1);
		while (i < argc)
		{
			if (argv[i + offset + 1][0] != 0)
				ls_list(argv[i + offset + 1], options);
			i++;
			if (i != argc && ls_file_is_dir(argv[i + offset + 1]))
				write(1, "\n", 1);
		}
	}
}
