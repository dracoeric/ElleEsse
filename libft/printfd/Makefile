#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/22 12:53:22 by erli              #+#    #+#              #
#    Updated: 2019/03/04 14:31:41 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=		../libft.a

SRCSDIR			=		srcs

OBJSDIR			=		objs

SRCS			=		main_printfd.c			main_printf.c		pfd_add_str.c	\
						pfd_add_char.c			pfd_manage_tag.c	pfd_read_tag.c	\
						pfd_convert.c			pfd_conv_doubles.c	pfd_unload_buf.c\
																					\
						pfd_num_type_size.c		pfd_num_to_str.c	pfd_arg_to_mem.c\
						pfd_arg_to_bin.c		pfd_write_num_to_str.c				\
						pfd_double_to_str.c		pfd_write_double_to_str.c			\
						pfd_write_whole_part_slide.c	pfd_remove_trailing_zeros.c	\
						pfd_write_whole_part.c	pfd_add_width.c						\
																					\
						pfd_conv_string.c		pfd_conv_char.c		pfd_no_conv.c	\
						pfd_conv_ptr.c												\
						pfd_conv_unsigned_decimals.c	pfd_conv_signed_decimals.c	\
																					\
						pfd_print_data.c

OBJS			=		$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

HEADER			=		includes/ft_printfd.h ../includes

CC				=		gcc -g

CFLAGS			=		-Wall -Werror -Wextra

INCL			=		-I includes/ -I ../includes

RM				=		rm -f

ADDLIB			=		-L ../ -lft

LIB				=		../libft.a

GREEN			=		"\x1B[32m"

DEFAULT			=		"\x1B[0m"

all				:		$(NAME)

$(NAME)			:		$(OBJS) $(HEADER)
						@echo "Adding: " $(GREEN) "ft_printf" $(DEFAULT)
						ar -rucs $(NAME) $(OBJS)

$(OBJSDIR)/%.o	:		$(SRCSDIR)/%.c $(HEADER)
						@mkdir -p $(OBJSDIR)
						$(CC) -c $(CFLAGS) $(INCL) $< -o $@

norm			:		delsav
						@echo "==== Norme"  $(GREEN) "printfd/srcs" $(DEFAULT) "===="
						norminette $(SRCSDIR) 
						@echo "==== Norme" $(GREEN) "printfd/includes/" $(DEFAULT) "===="
						norminette includes/

delsav			:
						$(RM) *~
						$(RM) */*~
						$(RM) \#*\#
						$(RM) */\#*\#

clean			:
						$(RM) $(OBJS)

fclean			:		clean
						$(RM) $(NAME)

re				:		fclean
						@make all

reset			:		delsav
						@make fclean
						rm -Rf $(OBJSDIR)

.PHONY			:		delsav clean fclean re reset
