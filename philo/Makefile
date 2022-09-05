NAME		=	philo

SRCS		=	./src/main.c ./src/check.c ./src/init.c \
				./src/life.c ./src/utils.c

OBJS 		= 	$(SRCS:.c=.o)

HEAD 		= 	./philo.h

CC 			= 	gcc

FLAGS 		= 	-Wall -Wextra -Werror #-fsanitize=thread 

RM 			= 	rm -f

.PHONY: 		all clean fclean re

all:			$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c   $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	@$(RM) $(OBJS)
	@echo "clean is done!"


fclean: clean
		@$(RM) $(NAME)
		@echo "full clean is done!"

re: 	fclean all