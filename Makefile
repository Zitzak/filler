# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgross <mgross@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/08 10:14:38 by mgross         #+#    #+#                 #
#    Updated: 2019/10/14 16:21:33 by mgross        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =	mgross.filler

SRCS_C = ./src/main.c ./src/first_input.c ./src/update_game.c \
./src/update_piece.c ./src/main_control.c ./src/fill_heatmap.c \
./src/update_enemy.c ./src/update_field.c ./src/update_heatmap.c \
./src/check_placement.c ./src/free_struct.c \

SRC_O = ./src/*.o

INCL = ./incl

FLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make re -C ./libft
	@gcc $(FLAGS) -o $(NAME) -I $(INCL) $(SRCS_C) -L ./libft/ -lft
	@echo "Compiling filler player.."
	@echo "SUCCES"

clean:
	@rm -f $(SRC_O)
	@echo "Cleaning..."
	@Make clean -C ./libft
	@echo "SUCCES"


fclean:
	@Make fclean -C ./libft
	@rm -rf $(NAME)
	@echo "Fcleaning filler player..."
	@echo "SUCCES"

re: fclean all