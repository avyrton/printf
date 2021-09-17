NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Werror -Wall -Wextra
AR 		= ar rcs
RM 		= rm -f

REC	= 	basex.c ft_printf.c printery_DSC.c printery_X.c printery.c
OBJ := ${REC:.c=.o}

HEADER = ft_printf

.PHONY: all clean fclean re

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): ${OBJ}
	${AR} ${NAME} $?

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all


