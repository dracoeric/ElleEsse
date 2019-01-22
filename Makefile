#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 17:49:02 by erli              #+#    #+#              #
#    Updated: 2019/01/22 13:29:57 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 			=	ft_ls

SRCSDIR			=	srcs

OBJSDIR			=	objs

SRCS			= 	main.c			ls_merge_sort.c			ls_list.c

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
					@make re

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