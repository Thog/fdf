# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#              #
#    Updated: 2016/05/25 14:19:55 by tguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -g -Wall -Wextra -Werror -O3 -march=native -I./includes
PRGFLAGS = -lft -lmlx -framework OpenGL -framework AppKit
CC = clang

NAME = fdf
LIB = libft
SRC = main.c utils.c hooks.c projections.c display.c parser.c image.c
SRCDIR = src
OUTDIR = out
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(addprefix $(OUTDIR)/, $(SRC:.c=.o))

$(NAME): $(OUTDIR) $(OBJ)
	@$(MAKE) -C $(LIB)
	@$(CC) -o $(NAME) $(CFLAGS) -I./libft -L./libft $(PRGFLAGS) $(OBJ)
$(OUTDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -I $(LIB) -o $@ -c $? $(CFLAGS)

$(OUTDIR):
	@mkdir -p $(OUTDIR)

clean:
	@$(MAKE) -C $(LIB) $@
	@rm -f $(OBJ)
	@rm -rf $(OUTDIR)

fclean: clean
	@$(MAKE) -C $(LIB) $@
	@rm -f $(NAME)

.PHONY: clean fclean re

re: fclean all

all: $(NAME)
