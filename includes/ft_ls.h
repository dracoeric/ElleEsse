/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:36:55 by erli              #+#    #+#             */
/*   Updated: 2019/01/23 14:20:38 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include <string.h>

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
# define LS_OPT_AT(x) (((x >> 10) & 1) == 1)
# define LS_OPT_E(x) (((x >> 11) & 1) == 1)
# define LS_OPT_MULT(x) (((x >> 12) & 1) == 1)

void			ls_merge_sort(char **tab, size_t len,
					int (*f)(char *, char *));
void			ls_list(char *path, int options);
void			ls_print_list(char *str, int count, int options);
void			ls_sort(char **arg, int len, int options);
void			ls_trim(char **arg, int *len, int options);
void			ls_print_format(char **arg, int len, int options);
void			ls_print_long(char **arg, int len, int options);
void			ls_print_mode(char *file, int options);
#endif

