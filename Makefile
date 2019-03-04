#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 17:49:02 by erli              #+#    #+#              #
#    Updated: 2019/03/04 15:10:56 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 			=	ft_ls

SRCSDIR			=	srcs

OBJSDIR			=	objs

SRCS			= 	main.c				ls_merge_sort.c			ls_list.c		\
					ls_sort.c			ls_sort_argv.c			ls_trim.c		\
					ls_print_format.c	ls_print_long.c			ls_print_mode.c	\
					ls_make_path.c		ls_print_total_block_size.c				\
					ls_print_links.c	ls_print_owner.c		ls_print_group.c\
					ls_print_size.c		ls_print_date.c			ls_get_width.c	\
					ls_file_is_dir.c	ls_print_file_name.c					\
										ls_max_major_minor.c					\
					ls_get_dev_major_minor.c

OBJS			= 	$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

CC				=	gcc -g

CFLAG			=	-Wall -Werror -Wextra

INCL			=	-I includes/ -I libft/includes/ 

RM				=	rm -f

MYLIB			=	libft/libft.a 

HEADER			=	includes/ft_ls.h

LIB				=	-L libft -lft #-lacl

GREEN			=		"\x1B[32m"

DEFAULT			=		"\x1B[0m"

all				:	libft $(NAME)

$(NAME)			:	$(OBJS) $(MYLIB) 
					@echo "Compiling:" $(GREEN) $(NAME) $(DEFAULT)
					$(CC) $(CFLAG) $(INCL) $(OBJS) -o $(NAME) $(LIB)

libft			:	
					@make -C libft/

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c includes/ft_ls.h
					@mkdir -p $(OBJSDIR)
					$(CC) -c $(CFLAG) $(INCL) $< -o $@

norm			:	delsav
					@echo "==== Norme" $(GREEN) "srcs" $(DEFAULT) "===="
					norminette $(SRCSDIR)
					@echo "==== Norme" $(GREEN) "includes" $(DEFAULT) "===="
					norminette includes
#					@echo "==== Norme" $(GREEN) "libft" $(DEFAULT) "===="
#					make -C libft norm
clean			:
					@$(RM) $(OBJS)

fclean			:	clean
					@$(RM) $(NAME)

re				:
					@make fclean
					@make all

delsav			:
					@$(RM) *~
					@$(RM) */*~
					@$(RM) \#*\#
					@$(RM) */*\#*\#

reset			:
					@make delsav
					@make fclean
					@make -C libft/ reset
					@rm -r $(OBJSDIR)

.PHONY			:	clean fclean delsav re reset libft
