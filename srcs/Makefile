NAME = push_swap

SRCS = main.c

OBJS = ${SRCS: .c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./ -fsanitize=address -g3

all : ${NAME} build

build :

	@echo "$(MAGENTA) /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\ "
	@echo "$(MAGENTA)( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )"
	@echo "$(MAGENTA) > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ < "
	@echo "$(MAGENTA) /\_/\    ░█▀█░█░█░█▀▀░█░█░░░░░█▀▀░█░█░█▀█░█▀█    /\_/\ "
	@echo "$(MAGENTA)( o.o )   ░█▀▀░█░█░▀▀█░█▀█░░░░░▀▀█░█▄█░█▀█░█▀▀   ( o.o )"
	@echo "$(MAGENTA) > ^ <    ░▀░░░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░▀░▀░▀░░    > ^ < "
	@echo "(     )                 meow meow                (     )"
	@echo "$(MAGENTA) /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\ "
	@echo "$(MAGENTA)( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )"
	@echo "$(MAGENTA) > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ < $(RESET)"

MAGENTA=\033[35m


${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME} 

re : fclean all

.PHONY : all clean fclean re