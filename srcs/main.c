/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:32:09 by erli              #+#    #+#             */
/*   Updated: 2019/01/25 12:31:44 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

static	void	manage_options_2(char c, int *options)
{
	char *str;

	str = "ls: illegal option -- %c\nusage: ls [-GRadfgltu@] [file ...]\n";
	if (c == 'g' && !(LS_OPT_LG(*options)))
	{
		*options = (*options | 128);
		*options = (*options & 2046);
	}
	else if (c == 'd' && !(LS_OPT_D(*options)))
		*options = (*options | 256);
	else if (c == 'G' && !(LS_OPT_UG(*options)))
		*options = (*options | 512);
	else
	{
		ft_printf(str, c);
		exit(0);
	}
}

static	void	manage_option(char c, int *options)
{
	if (c == 'l' && !(LS_OPT_L(*options)) && !(LS_OPT_LG(*options)))
		*options = (*options | 1);
	else if (c == 'R' && !(LS_OPT_UR(*options)))
		*options = (*options | 2);
	else if (c == 'a' && !(LS_OPT_A(*options)) && !(LS_OPT_F(*options)))
		*options = (*options | 4);
	else if (c == 'r' && !(LS_OPT_LR(*options)))
		*options = (*options | 8);
	else if (c == 't' && !(LS_OPT_T(*options)) && !(LS_OPT_F(*options)))
		*options = (*options | 16);
	else if (c == 'u' && !(LS_OPT_U(*options)) && !(LS_OPT_F(*options)))
		*options = (*options | 32);
	else if (c == 'f' && !(LS_OPT_F(*options)))
	{
		*options = (*options | 64);
		*options = (*options & 1995);
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

//	ft_merge_sort_tab_str(argv + 1, argv + 1, argc - 1);
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

/*
**	struct winsize win;
**	ioctl(0, TIOCGWINSZ, &win);
**	ft_printf("\e[48;5;226m\e[38;5;21mnum of col %hu\e[0m\n", win.ws_col);
*/
	i = 1;
	options = 0;
	offset = get_options(argc, argv, &options);
	check_arg(argc - offset, argv + offset);
	if (argc - offset > 2)
		options += 4096;
	if (argc - offset == 1)
		ls_list(".", options);
	else
	{
		ft_printf("argv = %ts\n", argv, argc);
		ls_sort(argv + offset + 1, argc - offset - 1, options);
		ft_printf("argv = %ts\n", argv, argc);
		ls_sort_argv(argv + (offset + 1), argc - offset - 1);
	}
	while (i + offset < argc)
	{
		if (argv[i + offset][0] != 0)
			ls_list(argv[i + offset], options);
		i++;
		if (i != argc - offset)
			write(1, "\n", 1);
	}
}
