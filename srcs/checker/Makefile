NAME =		../../checker

CC =		clang
CFLAGS =	-Wall -Wextra -Werror -g

INCLUDES =	-I ./includes -I ../../libft/includes
LIBFT = -L ../../libft -lft

SRC_FILES  =	checker.c \
				quicksort.c \
				get_next_line.c \
				debug.c

SRCS = $(addprefix srcs/,$(SRC_FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo ' '
	@make --no-print-directory -C ../../libft
	@clang $(OBJS) $(INCLUDES) $(CFLAGS) $(LIBFT) -o $@
	@echo "\033[1;32m\n[OK]\033[0m    \033[1;33mCreating \033[0m checker"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mCompiling\033[0m $(<F)"

clean:
	@$(RM) $(OBJS)
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mDeleting \033[0m object files of checker\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mDeleting \033[0m checker\n"

re: fclean all