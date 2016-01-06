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

CFLAGS = -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror -I./includes
CC = gcc

NAME = fdf
SRC = main.c
SRCDIR = src
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(SRC:.c=.o)
all: $(NAME)


$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

.PHONY: clean fclean re

re: fclean all
