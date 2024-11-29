NAME = cwarfare-game.out

CC = clang
CFLAGS = -I${INCLUDES} -lSDL2 -w

INCLUDES = ./includes/
SRCS = ${wildcard ./srcs/*.c}
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${OBJS} ${CFLAGS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
