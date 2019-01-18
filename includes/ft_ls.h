/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:36:55 by erli              #+#    #+#             */
/*   Updated: 2019/01/18 19:12:19 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

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

#endif

