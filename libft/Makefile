# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgross <mgross@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/28 13:12:07 by mgross         #+#    #+#                 #
#    Updated: 2019/08/06 15:47:16 by mgross        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_C = ft_atoi.c ft_bzero.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_islower.c ft_isprint.c ft_isupper.c \
ft_itoa.c ft_memalloc.c ft_memccpy.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memdel.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c \
ft_putstr.c ft_strcat.c ft_strchr.c \
ft_strclr.c ft_strcmp.c ft_strcpy.c \
ft_strdel.c ft_strdup.c ft_strequ.c \
ft_striter.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlen.c ft_strmap.c \
ft_strmapi.c ft_strncat.c ft_strncmp.c \
ft_strncpy.c ft_strnequ.c ft_strnew.c \
ft_strnstr.c ft_strrchr.c ft_strsplit.c \
ft_strstr.c ft_strsub.c ft_strtrim.c \
ft_tolower.c ft_toupper.c ft_putendl.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
ft_lstadd.c ft_lstiter.c ft_lstmap.c \
ft_nchar.c ft_lstfind_size.c \
ft_strcdup.c ft_stricdup.c ft_lstunlink.c \
ft_get_next_line.c ft_putstrarr.c ft_strndup.c \
ft_strarrdel.c ft_strarrlen.c ft_itoa_base.c \
ft_strlwr.c ft_strupr.c ft_itoa_long.c \
ft_append.c ft_insert.c ft_prepend.c \
ft_replace.c ft_strnewfill.c ft_select.c \
ft_strcalc_add.c ft_strcalc_mult.c \
ft_strcalc_div.c ft_strcalc_multexptwo.c \
ft_strcalc_valid.c ft_putnstr.c \
ft_putnchar.c ft_putnstr_fd.c \
ft_putnchar_fd.c ft_strcpy_newline.c \
ft_mem_array_alloc.c

SRC_O = ./*.o ./ft_printf/*.o

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make re -C ./ft_printf/
	@gcc -c -I./includes $(FLAGS) $(SRC_C)
	@echo "Compiling libft..."
	@ar rcs $(NAME) $(SRC_O)
	@echo "SUCCES"

clean:
	@rm -f $(SRC_O)
	@make clean -C ./ft_printf
	@echo "Cleaning..."
	@echo "SUCCES"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./ft_printf
	@echo "Fcleaning..."
	@echo "SUCCES"

re: fclean all
