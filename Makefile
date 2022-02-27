NAME = push_swap

CC = gcc
FLAGS = #-Wall -Wextra -Werror

UTILS = $(wildcard utils/*.c)
PILE_OP = $(wildcard piles_op/*.c)

C_FILES = $(wildcard *.c) ${UTILS} ${PILE_OP} 

O_FILES = ${C_FILES:.c=.o}
INCLUDES = -I . -I libft

LIBS = -L libft -lft
LIBFT = libft/libft.a

.c.o:
	${CC} ${FLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

all: ${LIBFT} ${NAME}

${LIBFT}:
	make -C libft

${NAME}: ${O_FILES}
	 ${CC} ${O_FILES} ${LIBS} -o ${NAME}

clean:
	rm -f ${O_FILES}

fclean: clean
	rm -f ${NAME}

re: fclean all

test: all
	./push_swap 1 3 6 4 2 5
