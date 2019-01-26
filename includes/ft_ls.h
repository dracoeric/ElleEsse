/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:36:55 by erli              #+#    #+#             */
/*   Updated: 2019/01/26 18:48:56 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include <string.h>
# include <sys/stat.h>
# include <dirent.h>

# define LS_OPT_L(x) ((x & 1) == 1)
# define LS_OPT_UR(x) (((x >> 1) & 1) == 1)
# define LS_OPT_A(x) (((x >> 2) & 1) == 1)
# define LS_OPT_LR(x) (((x >> 3) & 1) == 1)
# define LS_OPT_T(x) (((x >> 4) & 1) == 1)
# define LS_OPT_U(x) (((x >> 5) & 1) == 1)
# define LS_OPT_F(x) (((x >> 6) & 1) == 1)
# define LS_OPT_LG(x) (((x >> 7) & 1) == 1)
# define LS_OPT_D(x) (((x >> 8) & 1) == 1)
# define LS_OPT_UG(x) (((x >> 9) & 1) == 1)
# define LS_OPT_MULT(x) (((x >> 12) & 1) == 1)

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
void			ls_print_date(t_ls_data *ls_data, int i);
void			ls_print_file_name(t_ls_data *ls_data, int i);
char			*ls_make_path(char *base_path, char *file, char *full_path);
#endif
