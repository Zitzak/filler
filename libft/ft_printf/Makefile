# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgross <mgross@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/21 10:58:41 by mgross         #+#    #+#                 #
#    Updated: 2019/07/16 15:45:06 by mgross        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRC_C = ./src/main.c ./src/utillities.c ./src/main_conversion.c\
	./src/conversion_c.c ./src/conversion_s.c ./src/conversion_p.c\
	./src/conversion_signed.c ./src/conversion_signed_utillities.c \
	./src/conversion_unsigned.c ./src/conversion_f.c ./src/color_output.c \
	./src/conversion_f_utillities.c ./src/conversion_f_tfloat.c\
	./src/conversion_e.c ./src/conversion_e_utillities.c \
	./src/conversion_f_utillities2.c ./src/conversion_f_long.c \
	./src/conversion_f_tfloat_long.c ./src/conversion_c_special.c \
	./src/conversion_e_long.c ./src/utillities2.c \
	./src/conversion_signed_utillities2.c \
	./src/conversion_f_utillities3.c ./src/printf_main.c

SRC_O = ./*.o

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -c -I./includes $(FLAGS) $(SRC_C)
	@ar rcs $(NAME) $(SRC_O)

clean:
	@rm -f $(SRC_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all
