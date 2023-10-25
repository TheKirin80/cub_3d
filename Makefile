PARS_DIR	=	parsing
GAME_DIR	=	game
GARB_DIR	=	garbage


MAIN		=	main.c	
PARS_FILES	=	check_line.c\
				check_line_copy.c\
				get_next_line.c\
				get_next_line_utils.c\
				param_verif_background.c\
				utils_param_verif_background.c\
				parsing.c\
				tmp.c\
				old_map.c\
				verif_map.c\
				verif_map_tool_1.c\
				tool.c\
				tool2.c\
				tool3.c	
GAME_FILES	=	file.c\
				moove.c\
				raycasting.c\
				raycasting_init.c\
				rotate.c\
				raycasting_calc.c\
				raycasting_img.c
GARB_FILES	=	error.c\
				free.c\
				gest_close.c

PARS_SRCS = $(addprefix $(PARS_DIR)/, $(PARS_FILES))
GAME_SRCS = $(addprefix $(GAME_DIR)/, $(GAME_FILES))
GARB_SRCS = $(addprefix $(GARB_DIR)/, $(GARB_FILES))

OBJS_PARS	= ${PARS_SRCS:.c=.o}
OBJS_GAME	= ${GAME_SRCS:.c=.o}
OBJS_GARB	= ${GARB_SRCS:.c=.o}
OBJS_MAIN	= ${MAIN:.c=.o}

OBJS = $(OBJS_PARS) $(OBJS_GAME) $(OBJS_GARB) $(OBJS_MAIN) 

INC		= -I includes -I mlx_linux -I /usr/include

NAME 	= cub3D

CC 		= clang

RM 		= rm -f

CFLAGS	= -Wall -Wextra -Werror -g3 #-fsanitize=address,leak,undefined

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
