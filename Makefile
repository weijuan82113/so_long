# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 21:25:46 by wchen             #+#    #+#              #
#    Updated: 2022/12/30 18:18:20 by wchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

BONUS_NAME		=	so_long_bonus

UNAME			=	$(shell uname)

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror \
					-I$(INCLUDES_DIR) -I$(LIBFT_INC) -I$(MLX_INC)

ifdef WITH_TEST
#	CFLAGS		+= -g -fsanitize=address -fsanitize=undefined
	CFLAGS		+= -D LEAKS
endif

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
ifeq ($(UNAME), Darwin)
MLX_LIB			=	-L $(MLX_DIR) -lmlx_$(UNAME) -L/usr/X11R6/lib -lX11 -lXext -lm	\
						 -framework OpenGL -framework AppKit
else
MLX_LIB			=	-L $(MLX_DIR) -lmlx_$(UNAME) -L/usr/X11R6/lib -lX11 -lXext -lm
endif

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
										)
SL_OBJS			=	$(SL_SRCS:.c=.o)

##so_long_bonus
SL_BONUS_DIR			=	./srcs/bonus
SL_BONUS_SRCS			=	$(addprefix $(SL_BONUS_DIR),/map_initial.c		\
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
													/die_lstnew.c			\
													/attack_lstnew.c		\
													/enemy_move.c			\
													)
SL_BONUS_OBJS			=	$(SL_BONUS_SRCS:.c=.o)

all: libft_make mlx_make $(NAME)

$(NAME): $(MINILIBX) $(MAIN_OBJ) $(SL_OBJS)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(SL_OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $@

bonus: libft_make mlx_make $(BONUS_NAME)

$(BONUS_NAME): $(MINILIBX) $(MAIN_OBJ) $(SL_BONUS_OBJS)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(SL_BONUS_OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $@

libft_make:
	make -C $(LIBFT_DIR)

mlx_make:
	make -C $(MLX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f ${MAIN_OBJ}
	rm -f ${SL_OBJS}
	rm -f ${SL_BONUS_OBJS}

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME} $(BONUS_NAME)

re: fclean all

norm:
	@norminette -v
	norminette $(LIBFT_DIR) $(INCLUDES_DIR) $(SL_DIR) $(SL_BONUS_DIR)

test:
	@make re all WITH_TEST=1

bonus_test:
	make bonus WITH_TEST=1
