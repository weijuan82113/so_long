/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:45:19 by wchen             #+#    #+#             */
/*   Updated: 2022/12/18 10:30:16 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "error_msg.h"
# include "so_long.h"
# include "img.h"
# include "so_long_const.h"
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_bfs
{
	t_queue		*q;
	int			*start_vertex;
	int			current_vertex;
	t_node		*temp;
	int			*adj_vertex;
}				t_bfs;

typedef struct s_graph
{
	int 	num_vertex;
	t_node	**adj_lsts;
	int		*visited;
}			t_graph;

typedef struct s_game_board
{
	char		**map;
	t_node		*map_head;
	int			collect_count;
	int			exit_count;
	int			player_count;
	int			empty_count;
	int			wall_count;
	t_node		*judge_obj;
	int			x;
	int			y;
	int			size;
	int			position;
	int			goal_position;
	int			step;
	t_graph		*graph;
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

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	t_img			*img_head;
	t_game_board	*g;
}					t_mlx;

t_game_board	*map_initial(int argc, char **argv);
void			ft_error(char *chr);
int				object_validation(char input_chr, t_game_board *g_board);
void			wall_validation(t_game_board *g_board, char input_chr, int i);
void			map_validation(t_game_board *g_board);
void			bfs_validation(t_game_board *g_board);
t_mlx			*mlx_initial(int argc, char **argv);
t_img			*img_lstnew(void *mlx, char object, int size);
void			img_lstadd_back(t_img **head, t_img *new);
void			win_initial(void *mlx, void *win,
					t_game_board *g, t_img *img_head);
int				key_hook(int keycode, t_mlx *t_mlx);
int				my_loop(t_mlx *t_mlx);
void			game_over(t_mlx *t_mlx, char *exit_msg);
void			free_all(t_mlx *t_mlx);
int				destroy_hook(t_mlx *t_mlx);
void			bfs_obj_initial(t_game_board *g, char obj, int i);
t_graph			*graph_create(int vertex_count, char **map, int x);
void			edge_initial(t_graph *graph, t_game_board *g);
void			free_graph(t_graph *graph);

#endif
