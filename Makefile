# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwong <juwong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/20 11:00:07 by juwong            #+#    #+#              #
#    Updated: 2018/09/28 19:49:10 by juwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= push_swap
NAME2	= checker

SRC1	=	push_swap.c moves.c error_handling.c initialization.c helper.c \
merge_sort.c sorts.c print.c algorithm.c sortsmall.c

SRC2	=	checker.c moves.c error_handling.c initialization.c helper.c \
print.c

OBJ1		= $(addprefix $(OBJDIR),$(SRC1:.c=.o))
OBJ2		= $(addprefix $(OBJDIR),$(SRC2:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g 

LIBFT	= ./libft/libft.a
LIBINC	= -I./libft/includes/
LIBLINK	= -L./libft -lft

PRINTFLINK = -L./printf/ -lftprintf

SRCDIR	= ./sources/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj libft $(NAME2) $(NAME1)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME2): $(OBJ2)
	$(CC) $(LDFLAGS) -o $(NAME2) $(OBJ2) $(LIBLINK) -L. -lftprintf

$(NAME1): $(OBJ1)
	$(CC) $(LDFLAGS) -o $(NAME1) $(OBJ1) $(LIBLINK) -L. -lftprintf


clean:
	rm -rf $(OBJDIR)
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)
	make -C ./libft fclean

re: fclean all