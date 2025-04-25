NAME    = push_swap

CFLAGS  = -Wall -Werror -Wextra

RM      = rm -f

SRCS    = srcs/main.c srcs/parsing.c srcs/stack.c srcs/utils.c utils/utils1.c utils/utils2.c utils/utils3.c

OBJ     = $(SRCS:.c=.o)


FT_PRINTF	 = ft_printf/libftprintf.a

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

$(FT_PRINTF):
	$(MAKE)	-C ft_printf

$(NAME): $(OBJ) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(FT_PRINTF)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ft_printf clean

fclean: clean
	$(RM) $(OBJ)
	$(MAKE) -C ft_printf fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 