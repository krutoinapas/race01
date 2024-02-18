CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic

NAME := part_of_the_matrix

all: $(NAME)
	
$(NAME):
	$(CC) $(CFLAGS) -Iinc -o $(NAME) src/*.c

clean:
	rm -rf $(NAME)

uninstall:
	rm -rf $(NAME)

reinstall:
	make uninstall
	make



