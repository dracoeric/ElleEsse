/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:08:07 by erli              #+#    #+#             */
/*   Updated: 2019/03/03 11:12:07 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>

unsigned int		ft_double_exponent(long double nb, size_t double_size,
					size_t exp_nb_bit);
unsigned long long	ft_double_whole(long double nb, size_t double_size,
					size_t exp_nb_bit);

int					ft_atoi(const char *str);
void				ft_free_mat_int(int **mat, int i);
int					ft_int_in_ptr(int a, int *tab, size_t len);
void				ft_merge_sort_tab(int *src, int *dest, size_t len);
void				ft_merge_sort_tab_str(char **src, char **dest, size_t len);
void				ft_swap_int(int *a, int *b);
void				ft_swap_str(char **a, char **b);

int					ft_char_at_pos(char c, char *str);
int					ft_char_in_str(char c, char *str);
void				ft_free_mat_char(char **mat, int i);
char				*ft_itoa(int nb);
char				*ft_dtoa(double nb, int precision);
char				*ft_ldtoa(long double nb, int precision);
int					ft_str_made_of_str(char *str, char *base);
int					ft_tolower(int c);
int					ft_toupper(int c);

int					get_next_line(int fd, char **line);
int					ft_printf(const char *format, ...);
int					ft_printfd(int fd, char *format, ...);

int					ft_msg_int(int fd, char *msg, int ret);
void				*ft_msg_ptr(int fd, char *msg, void *ptr);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

void				ft_bzero(void *s, size_t len);
void				*ft_memalloc(size_t n);
void				*ft_memalloc_c(size_t n, int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dsl, const void *src, size_t n);
void				ft_memdel(void **ptr);
void				*ft_memmove(void *dsl, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);

void				ft_printstrsplit(char **split);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(const char *str);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(const char *str);
void				ft_putstr_fd(const char *str, int fd);

char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *str, int c);
void				ft_strclr(char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **ptr);
char				*ft_strdup(const char *src);
int					ft_strequ(const char *s1, const char *s2);
void				ft_striter(char *str, void (*f)(char *));
void				ft_striteri(char *str, void (*f)(unsigned int, char*));
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoinfree(char **s1, char **s2, int n);
size_t				ft_strlcat(char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strmap(const char *src, char (*f)(char));
char				*ft_strmapi(const char *src, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t n);
char				*ft_strnstr(const char *haysack, const char *needle,
						size_t n);
char				*ft_strrchr(const char *str, int c);
char				**ft_strsplit(const char *src, char c);
char				*ft_strstr(const char *haysack, const char *needle);
char				*ft_strsub(const char *str, unsigned int begin, size_t len);
char				*ft_str_to_lower(char *str);
char				*ft_str_to_upper(char *str);
char				*ft_strtrim(const char *src);

#endif
