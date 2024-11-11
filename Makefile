TESTED_FOLDER_NAME = libft-temp

NAME = test.out

CC = gcc
CFLAGS = -Iincludes -w
LDFLAGS = -Llibs -lft -lbsd

TESTED_FOLDER = ../${TESTED_FOLDER_NAME}

all: execute fclean
	
execute: getfiles ${NAME} 
	./${NAME}

getfiles:
	cd ${TESTED_FOLDER} && make -s && cp libft.a ../libft-tester/libs && cp libft.h ../libft-tester/includes && make -s fclean

${NAME}: main.o
	${CC} -o ${NAME} main.o ${LDFLAGS}
	
main.o: main.c
	${CC} -c main.c ${CFLAGS}

clean:
	rm -f main.o

fclean: clean
	rm -f ${NAME}
	rm -f includes/libft.h
	rm -f libs/libft.a

re: fclean all

.SILENT: