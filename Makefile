# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgross <mgross@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/08 10:14:38 by mgross         #+#    #+#                 #
#    Updated: 2019/08/26 15:44:45 by Marvin        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =	mgross.filler

SRCS =	./src/main.c ./src/first_input.c ./src/update_game.c \
		./src/update_piece.c ./src/main_control.c ./src/fill_heatmap.c \
		./src/fill_heatmap2.c ./src/update_enemy.c ./src/update_field.c \
		./src/update_heatmap.c

# SRC_O =	
INCL =	./incl

FLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(NAME) -I $(INCL) $(SRCS) -L ./libft/ -lft

fclean:
	rm -rf $(NAME)

re: fclean all