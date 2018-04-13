NAME= fillit
CC= gcc
SRC= ft_check_file.c \
	  ft_lstetri.c \
	  ft_plc.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_read_st.c \
	  ft_strdup.c \
	  ft_strlen.c \
	  main.c
FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<
