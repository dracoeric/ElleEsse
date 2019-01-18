/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:32:09 by erli              #+#    #+#             */
/*   Updated: 2019/01/18 19:21:46 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static	void	manage_option(char c, int *options)
{
	if (c == 'l' && !(LS_OPT_L(*options)) && !(LS_OPT_LG(*options)))
		*options = (*options | 1);
	else if (c == 'R' && !(LS_OPT_UR(*options)))
		*options = (*options | 2);
	else if (c == 'a' && !(LS_OPT_A(*options)))
		*options = (*options | 4);
	else if (c == 'r' && !(LS_OPT_LR(*options)))
		*options = (*options | 8);
	else if (c == 't' && !(LS_OPT_T(*options)) && !(LS_OPT_F(*options)))
		*options = (*options | 16);
	else if (c == 'u' && !(LS_OPT_U(*options)))
		*options = (*options | 32);
	else if (c == 'f' && !(LS_OPT_F(*options)))
	{
		*options = (*options | 64);
		*options = (*options & 2031);
	}
	else if (c == 'g' && !(LS_OPT_LG(*options)))
	{
		*options = (*options | 128);
		*options = (*options & 2046);
	}
	else if (c == 'd' && !(LS_OPT_D(*options)))
		*options = (*options | 256);
	else if (c == 'G' && !(LS_OPT_UG(*options)))
		*options = (*options | 512);
	else if (c == '@' && !(LS_OPT_AT(*options)))
		*options = (*options | 1024);
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
			if (ft_str_made_of_str(argv[i] + 1, "lRartufgdG@") == 1)
			{
				j = 1;
				while (argv[i][j] != '\0')
					manage_option(argv[i][j++], options);
				i++;
			}
			else
				loop = 0;
		}
		else
			loop = 0;
	}
	return (i - 1);
}

int				main(int argc, char **argv)
{
	int options;
	int offset;
	int i;

	i = 1;
	options = 0;
	offset = get_options(argc, argv, &options);
	ft_printf("options = %d\n", options);
	while (i + offset < argc)
	{
		ft_printf("arg %d = '%s'\n", i, argv[i + offset]);
		i++;
	}
}