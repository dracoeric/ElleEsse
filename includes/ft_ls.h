/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:36:55 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 15:09:14 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include <string.h>
# include <sys/stat.h>
# include <dirent.h>

# define SIX_MONTHS 15778800

# define LS_OPT_L 1
# define LS_OPT_UR (1 << 1)
# define LS_OPT_A (1 << 2)
# define LS_OPT_LR (1 << 3)
# define LS_OPT_T (1 << 4)
# define LS_OPT_U (1 << 5)
# define LS_OPT_F (1 << 6)
# define LS_OPT_LG (1 << 7)
# define LS_OPT_D (1 << 8)
# define LS_OPT_UG (1 << 9)
# define LS_OPT_MULT (1 << 12)

typedef	struct	s_ls_data
{
	DIR				*dirp;
	char			*base_path;
	char			is_dir;
	char			**arg;
	struct stat		*data;
	int				count;
	int				options;
	unsigned int	max_link;
	unsigned int	max_size;
	unsigned int	max_minor;
	unsigned int	max_uid;
	unsigned int	max_gid;
}				t_ls_data;

void			ls_merge_sort(char **tab, size_t len,
					int (*f)(char *, char *));
int				ls_file_is_dir(char *file);
void			ls_list(char *path, int options);
void			ls_sort(char **arg, int len, int options);
int				ls_sort_argv(char **arg, int len);
void			ls_trim(char **arg, int *len, int options);
void			ls_print_format(t_ls_data *ls_data);
void			ls_print_long(t_ls_data *ls_data);
void			ls_print_total_block_size(t_ls_data *ls_data);
void			ls_print_mode(t_ls_data *ls_data, int i, int path_len);
unsigned int	ls_get_width(unsigned int nb);
void			ls_print_links(t_ls_data *ls_data, int i);
void			ls_print_owner(t_ls_data *ls_data, int i);
void			ls_print_group(t_ls_data *ls_data, int i);
void			ls_print_size(t_ls_data *ls_data, int i);
void			ls_max_major_minor(t_ls_data *ls_data, int i);
void			ls_get_dev_major_minor(struct stat *data, unsigned int *tab);
void			ls_print_date(t_ls_data *ls_data, int i);
void			ls_print_file_name(t_ls_data *ls_data, int i);
char			*ls_make_path(char *base_path, char *file, char *full_path);
#endif
