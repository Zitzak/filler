# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgross <mgross@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/02 11:22:05 by mgross         #+#    #+#                 #
#    Updated: 2019/10/03 16:46:19 by mgross        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =  unit_test

SRC = ./src/test_filler.c ./src/run_vm.c ./src/buf_to_array.c ./src/print_result.c \
		./src/get_input.c ./src/utilities.c ./src/maps_to_files.c \
		./src/maps_to_stdout.c ./src/get_paths.c ./src/calc_pos.c

INCL = ./incl/test_filler.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -o $(NAME) $(FLAGS) -I $(INCL) $(SRC)
	@rm -rf ./test_results.txt
	@echo "Compiling Unit Test"
	@echo "SUCCES"
fclean:
	@rm -rf $(NAME)
	@rm -rf ./filler.trace

re: fclean all