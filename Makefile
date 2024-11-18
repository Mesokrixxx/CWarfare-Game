NAME = cwarfare-game.out

CC = cc
CFLAGS = -I${INCLUDES}

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
