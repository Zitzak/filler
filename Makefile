# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgross <mgross@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/08 10:14:38 by mgross         #+#    #+#                 #
#    Updated: 2019/10/02 15:54:35 by mgross        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =	./players/mgross.filler

SRCS =	./src/main.c ./src/first_input.c ./src/update_game.c \
		./src/update_piece.c ./src/main_control.c ./src/fill_heatmap.c \
		./src/fill_heatmap2.c ./src/update_enemy.c ./src/update_field.c \
		./src/update_heatmap.c ./src/check_placement.c ./src/free_struct.c \

INCL = ./incl

FLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make re -C ./libft
	@gcc $(FLAGS) -o $(NAME) -I $(INCL) $(SRCS) -L ./libft/ -lft
	@echo "Compiling filler player.."
	@echo "SUCCES"

fclean:
	@rm -rf $(NAME)
	@echo "Fcleaning filler player..."
	@echo "SUCCES"

re: fclean all