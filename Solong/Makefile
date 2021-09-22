NAME		= so_long

CC			= gcc

CFLAG		= -Wall -Wextra -Werror -g -fsanitize=address

MLX_FLAG	= -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -lz

MLX_PATH	= ./mlx_linux

SRC =	so_long.c \
		./check_map/check_map.c \
		./check_map/check_map2.c \
		./error/error_msg.c \
		./error/error_msg2.c \
		./init_display_end/game_end.c \
		./init_display_end/game_init.c \
		./init_display_end/display_map.c \
		./event/event.c \
		./event/event_move.c \
		./event/event_move2.c \
		./utils/utils1.c \
		./utils/utils2.c \
		./utils/get_next_line.c \
		
SRC_OBJ		= $(SRC:.c=.o)

all:	$(NAME)

.c.o:
			${CC} ${CFLAGS} -Imlx_linux -c $< -o ${<:.c=.o}

$(NAME):	$(SRC_OBJ)
		make -C ${MLX_PATH}
		$(CC) $(CFLAG) -o $(NAME) $(SRC_OBJ) $(MLX_FLAG) 

clean:
				make -C ${MLX_PATH} clean
				rm -f ${SRC_OBJ}

fclean: 		clean
				make -C ${MLX_PATH} clean
				rm -f ${NAME}

re:         	fclean all

.PHONY:        all clean fclean re
