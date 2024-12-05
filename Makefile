NAME = cwarfare-game.out

CC = clang
CFLAGS = -g3 -I${INCLUDES} -lSDL2 -lm -w

INCLUDES = ./includes/
SRCS =	${wildcard ./srcs/*.c}
SRCS +=	${wildcard ./srcs/entities/*.c}
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${OBJS} ${CFLAGS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
