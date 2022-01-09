NAME = push_swap

LIBFT = libft/libft.a
LIBFT_INC = -L libft -lft
LIBFT_DIR = libft
LIBFT_H = libft/libft.h
LIBFT_REPO = https://github.com/adesgran/libft_extended.git

CC = gcc
C_FLAGS = -Wall -Wextra -Werror

C_FILES = $(wildcard *.c) $(wildcard piles_op/*.c) $(wildcard utils/*.c)
H_FILES = -I ${LIBFT_DIR} -I .

all: ${LIBFT} ${NAME}

${LIBFT}:
	if [ ! -d "./libft" ]; then git clone ${LIBFT_REPO} libft; fi
	make -C libft

${NAME}:
	${CC} ${C_FLAGS} ${H_FILES} ${C_FILES} ${LIBFT_INC} -o ${NAME}

clean:
	rm -r ${NAME}

fclean: clean
	make fclean -C ${LIBFT_DIR}

re: clean all
