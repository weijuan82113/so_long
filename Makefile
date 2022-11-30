# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchen <wchen@42studen>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 21:25:46 by wchen             #+#    #+#              #
#    Updated: 2022/12/01 00:54:12 by wchen            ###   ########.fr        #
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
# Sl_DIR			=	./srcs/so_long
# Sl_SRCS			=	$(addprefix $(Sl_DIR),/list_init.c		\
# 										)
# SL_OBJS	=	$(SL_SRCS:.c=.o)

all: libft_make mlx_make $(NAME)

$(NAME): $(MINILIBX) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(LIBFT_LIB) $(MLX_LIB) -o $@


libft_make:
	make -C $(LIBFT_DIR)

mlx_make:
	make -C $(MLX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f ${MAIN_OBJ}

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME}

re: fclean all

