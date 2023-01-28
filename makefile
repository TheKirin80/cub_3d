SRC_DIR	= src

SRC_FILES	= tool2.c gest_close.c moove.c file.c main.c get_next_line.c get_next_line_utils.c map.c param_verif_map.c tool.c error.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

SRCSBON	=

INC		= -I includes -I mlx_linux -I /usr/include

OBJS	= ${SRCS:.c=.o}

OBJSBON	= ${SRCSBON:.c=.o}

NAME 	= cub_3d

CC 		= clang

RM 		= rm -f

CFLAGS	= -Wall -Wextra -Werror #-g3 #-O3 #-fsanitize=address

all:		${NAME}

.c.o :
			$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

${NAME}:	${OBJS} cub_3d.h
			@make --no-print-directory -C mlx_linux
			$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

bonus:		${OBJS} ${OBJSBON} 
			${CCLIB} ${OBJS} ${OBJSBON}

clean:		
			${RM} ${OBJS} ${OBJSBON}

fclean:		clean
			${RM} ${NAME}
			@make clean --no-print-directory  -C mlx_linux/

re:			fclean all

.PHONY:		all clean fclean re bonus
