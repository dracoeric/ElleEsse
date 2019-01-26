#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 17:49:02 by erli              #+#    #+#              #
#    Updated: 2019/01/26 17:23:41 by erli             ###   ########.fr        #
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
					ls_print_size.c		ls_print_date.c							\
										ls_print_file_name.c					\

OBJS			= 	$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

CC				=	gcc

CFLAG			=	-Wall -Werror -Wextra

INCL			=	-I includes/ -I libft/includes/

RM				=	rm -f

LIB				=	libft/libft.a 


all				:	$(NAME)

$(NAME)			:	$(OBJS) $(LIB) includes/ft_ls.h
					$(CC) $(CFLAG) $(INCL) $(LIB) $(OBJS) -o $(NAME)

$(LIB)			:	
					@make -C libft/
					@make -C libft/ clean

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c includes/ft_ls.h
					@mkdir -p $(OBJSDIR)
					$(CC) -c $(CFLAG) $(INCL) $< -o $@

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
					@make -C libft/ delsav
					@make -C libft/ fclean
					@rm -r objs libft/objs

.PHONY			:	clean fclean delsav re reset 
