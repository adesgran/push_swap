NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror

UTILS = $(wildcard gnl/*.c)
PILE_OP = $(wildcard ft_printf/*.c)

C_FILES = ${UTILS} ${PILE_OP} 

O_FILES = ${C_FILES:.c=.o}
INCLUDES = -I .

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
