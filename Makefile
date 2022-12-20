# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 21:25:46 by wchen             #+#    #+#              #
#    Updated: 2022/12/20 22:14:30 by wchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
UNAME			=	$(shell uname)

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I$(INCLUDES_DIR)\
					-I$(LIBFT_INC) -I$(MLX_INC)

MAIN			=	./main.c
MAIN_OBJ		=	$(MAIN:.c=.o)

INCLUDES_DIR	=	./includes

##libft
LIBFT_DIR		=	./libft
LIBFT_INC		=	$(LIBFT_DIR)
LIBFT_LIB		=	-L $(LIBFT_DIR) -lft

##minilibx
MLX_DIR			=	./minilibx-linux
MLX_INC			=	$(MLX_DIR)
MLX_LIB			=	-L $(MLX_DIR) -lmlx_$(UNAME) -L/usr/X11R6/lib -lX11 -lXext -lm	\
						 -framework OpenGL -framework AppKit

##so_long
SL_DIR			=	./srcs
SL_SRCS			=	$(addprefix $(SL_DIR),/map_initial.c		\
										/ft_error.c				\
										/object_validation.c	\
										/wall_valiation.c		\
										/map_validation.c		\
										/bfs_validation.c		\
										/mlx_initial.c			\
										/img_lstnew.c			\
										/img_lstadd_back.c		\
										/win_initial.c			\
										/key_hook.c				\
										/my_loop.c				\
										/game_over.c			\
										/destroy_hook.c			\
										/free_all.c				\
										/bfs_obj_initial.c		\
										/graph_create.c			\
										/edge_initial.c			\
										/free_graph.c			\
										/sprite_lstnew.c		\
										/enemy_move.c			\
										)
SL_OBJS			=	$(SL_SRCS:.c=.o)


all: libft_make mlx_make $(NAME)

$(NAME): $(MINILIBX) $(MAIN_OBJ) $(SL_OBJS)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(SL_OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $@


libft_make:
	make -C $(LIBFT_DIR)

mlx_make:
	make -C $(MLX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f ${MAIN_OBJ}
	rm -f ${SL_OBJS}

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME}

re: fclean all

