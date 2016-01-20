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
OUTDIR = out
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(addprefix $(OUTDIR)/, $(SRC:.c=.o))
all: $(NAME)

$(NAME): mkOut $(OBJ)
	(cd $(LIB) && $(MAKE))
	$(CC) -o $(NAME) $(CFLAGS) -I./libft -L./libft $(PRGFLAGS) $(OBJ)
$(OUTDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -I $(LIB) -o $@ -c $? $(CFLAGS)

mkOut:
	@mkdir -p $(OUTDIR)

clean:
	@(cd $(LIB) && $(MAKE) $@)
	@rm -f $(OBJ)
	@rm -rf $(OUTDIR)

fclean: clean
	@(cd $(LIB) && $(MAKE) $@)
	@rm -f $(NAME)

.PHONY: clean fclean re

re: fclean all
