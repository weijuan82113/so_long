/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:45:19 by wchen             #+#    #+#             */
/*   Updated: 2022/12/09 01:28:51 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "error_msg.h"
# include "so_long.h"
# include "img.h"
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_game_board
{
	void	*mlx;
	char	**map;
	t_node	*map_head;
	int		collect_count;
	int		exit_count;
	int		player_count;
	int		empty_count;
	int		wall_count;
	int		x;
	int		y;
	int		size;
}			t_game_board;

typedef struct s_img
{
	char			obj;
	void			*img;
	char			*img_path;
	int				w;
	int				h;
	struct s_img	*next;
}				t_img;


t_game_board	*map_initial(int argc, char **argv,t_game_board *g_board);
void			ft_error(char *chr);
int				object_validation(char input_chr, t_game_board *g_board);
void			wall_validation(t_game_board *g_board, char input_chr, int i);
void			map_validation(t_game_board *g_board);
void			mlx_initial(t_game_board *g_board);
t_img			*img_lstnew(void *mlx, char object, int size);
void			img_lstadd_back(t_img **head, t_img *new);
#endif
