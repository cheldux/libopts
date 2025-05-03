# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 14:49:45 by thschnei          #+#    #+#              #
#    Updated: 2025/05/03 13:20:05 by thschnei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libopts.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2
IFLAGS = -I../ft_printf
CFLAGS += $(IFLAGS)

FILES =	args.c \
		callstack.c \
		error.c \
		info.c \
		opt.c \
		utils.c \

SRC_DIR = src/

FILES := $(addprefix $(SRC_DIR), $(FILES))

OBJS = $(FILES:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) rcs $@ $(OBJS)

re : fclean all

clean :
	$(RM) $(OBJS)
fclean :
	$(RM) $(OBJS) $(NAME)
.PHONY: all re clean fclean
