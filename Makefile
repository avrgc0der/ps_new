NAME    = push_swap

CFLAGS  = -Wall -Werror -Wextra
CFLAGS += -g3

RM      = rm -f

SRCS    =  $(wildcard srcs/*.c srcs/moves/*.c utils/*.c)

OBJ     = $(SRCS:.c=.o)

all: $(NAME) build

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


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 