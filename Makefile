# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 14:49:45 by thschnei          #+#    #+#              #
#    Updated: 2025/04/29 22:24:25 by thschnei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libopts.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2
IFLAGS = -I../ft_printf
CFLAGS += $(IFLAGS)
CFLAGS += -ggdb #-fsanitize=address

FILES =	args.c \
		callstack.c \
		error.c \
		info.c \
		opt.c \
		utils.c \

SRC_DIR = src/
OBJ_DIR = obj/

FILES := $(addprefix $(SRC_DIR), $(FILES))

#libft = includes/libft/
#libft_a = $(addprefix $(libft), libft.a)

#libftprintf = includes/ft_printf/
#libftprintf_a = $(addprefix $(libftprintf), libftprintf.a)

OBJS = $(FILES:%.c=%.o)

#Building the binary
all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) rcs $@ $(OBJS)

#$(libftprintf_a) :
#	make -s -C $(libftprintf)

#Cleanup
re : fclean all

clean :
	$(RM) $(OBJS)
fclean :
	$(RM) $(OBJS) $(NAME)
.PHONY: all re clean fclean
