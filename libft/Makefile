#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 17:45:59 by erli              #+#    #+#              #
#    Updated: 2019/03/04 14:32:16 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=		libft.a

SRCSDIR		=		srcs

OBJSDIR		=		objs

SRCS		=							ft_double_whole.c	ft_double_exponent.c\
					ft_atoi.c			ft_char_at_pos.c	ft_itoa.c			\
					ft_char_in_str.c	ft_free_mat_int.c	get_next_line.c		\
					ft_tolower.c		ft_toupper.c		ft_free_mat_char.c	\
					ft_isalpha.c		ft_isdigit.c		ft_isalnum.c		\
					ft_isascii.c		ft_isprint.c		ft_msg_int.c		\
					ft_msg_ptr.c		ft_dtoa.c			ft_ldtoa.c			\
					ft_int_in_ptr.c		ft_swap_int.c		ft_swap_str.c		\
															ft_str_made_of_str.c\
					ft_merge_sort_tab.c	ft_merge_sort_tab_str.c					\
																				\
					ft_bzero.c			ft_memalloc.c		ft_memalloc_c.c		\
					ft_memccpy.c		ft_memchr.c			ft_memcmp.c			\
					ft_memcpy.c			ft_memdel.c			ft_memmove.c		\
					ft_memset.c													\
																				\
					ft_printstrsplit.c	ft_putchar.c		ft_putchar_fd.c		\
					ft_putendl.c		ft_putendl_fd.c		ft_putnbr.c			\
					ft_putnbr_fd.c		ft_putstr.c			ft_putstr_fd.c		\
																				\
					ft_strcat.c			ft_strchr.c			ft_strclr.c			\
					ft_strcmp.c			ft_strcpy.c			ft_strdel.c			\
					ft_strdup.c			ft_strequ.c			ft_striter.c		\
					ft_striteri.c		ft_strjoin.c		ft_strjoinfree.c	\
					ft_strlcat.c		ft_strlen.c			ft_strmap.c			\
					ft_strmapi.c		ft_strncat.c		ft_strncmp.c		\
					ft_strncpy.c		ft_strnequ.c		ft_strnew.c			\
					ft_strnstr.c		ft_strrchr.c		ft_strsplit.c		\
					ft_strstr.c			ft_strsub.c			ft_str_to_lower.c	\
					ft_str_to_upper.c	ft_strtrim.c																				
OBJS		=		$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

CC			=		gcc

CFLAG		=		-Wall -Werror -Wextra

INCL		=		-I includes/

HEADER		=		includes/libft.h 			\
					includes/get_next_line.h

RM			=		rm -f

GREEN			=		"\x1B[32m"

DEFAULT			=		"\x1B[0m"

all			:		$(NAME) printfd

$(NAME)		:		$(OBJS) $(HEADER)
					@echo "Compiling: " $(GREEN) $(NAME) $(DEFAULT)
					ar -rucs $(NAME) $(OBJS)

printfd		:		
					make -C printfd

$(OBJSDIR)/%.o			:		$(SRCSDIR)/%.c
					@mkdir -p $(OBJSDIR)
					$(CC) $(CFLAG) $(INCL) -c $< -o $@

norm		:		delsav
					@echo "==== Norme" $(GREEN) "libft/srcs" $(DEFAULT) "===="
					norminette $(SRCSDIR)
					@echo "==== Norme" $(GREEN) "libft/includes" $(DEFAULT) "===="
					norminette includes
					@echo "==== Norme" $(GREEN) "libft/printfd" $(DEFAULT) "===="
					make -C printfd norm

clean		:
					@$(RM) $(OBJS)
					@make -C printfd clean

fclean		:		clean
					@$(RM) $(NAME)
					@make -C printfd fclean

re			:
					@make fclean
					@make -C printfd fclean
					@make all

delsav		:
					@$(RM) */*~
					@$(RM) *~
					@$(RM) \#*\#
					@$(RM) */\#*\#

reset		:
					@make fclean
					@make -C printfd reset
					@make delsav
					@rm -Rf objs/

.PHONY		:		clean delsav re fclean reset printfd
