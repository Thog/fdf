#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#             *#
#*   Updated: 2015/12/02 19:47:24 by tguillem         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CFLAGS = -g -Wall -Wextra -Werror -I./includes
PRGFLAGS = -lmlx -framework OpenGL -framework AppKit
CC = gcc

NAME = fdf
LIB = libft
SRC = main.c utils.c hooks.c
SRCDIR = src
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	(cd $(LIB) && $(MAKE))
	$(CC) -o $(NAME) $(CFLAGS) -I./libft -L./libft $(PRGFLAGS) $(OBJ)
%.o: $(SRCDIR)/%.c
	$(CC) -I $(LIB) -o $@ -c $? $(CFLAGS)


clean:
	@(cd $(LIB) && $(MAKE) $@)
	@rm -f $(OBJ)

fclean: clean
	@(cd $(LIB) && $(MAKE) $@)
	@rm -f $(NAME)

.PHONY: clean fclean re

re: fclean all
