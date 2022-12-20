/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:50:18 by wchen             #+#    #+#             */
/*   Updated: 2022/12/20 22:25:07 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	door_open(t_mlx *t_mlx)
{
	int		i;
	int		x;
	int		y;
	char	**map;

	i = 0;
	x = t_mlx->g->x;
	y = t_mlx->g->y;
	map = t_mlx->g->map;
	while (i < x * y)
	{
		if (map[i / x][i % x] == 'E')
		{
			map[i / x][i % x] = 'G';
			break ;
		}
		i++;
	}
}

static void	attack_animation(t_mlx *t_mlx)
{
	t_img			*sprite;
	int				p;
	void			*s_img;
	t_game_board	*g;

	sprite = t_mlx->img_sprite;
	p = t_mlx->g->position;
	g = t_mlx->g;
	while (sprite != NULL)
	{
		s_img = sprite->img;
		mlx_put_image_to_window(t_mlx->mlx, t_mlx->win, s_img, (p % g->x)
			* g->size, (p / g->x) * g->size);
		usleep(100000);
		sprite = sprite->next;
	}
	usleep(250000);
	t_mlx->g->attak = 0;
}

int	my_loop(t_mlx *t_mlx)
{
	if (t_mlx->g->attak == 1)
		attack_animation(t_mlx);
	else
		enemy_move(t_mlx);
	win_initial(t_mlx->mlx, t_mlx->win, t_mlx->g, t_mlx->img_head);
	mlx_string_put(t_mlx->mlx, t_mlx->win, 10, 25, RED, "STEP");
	mlx_string_put(t_mlx->mlx, t_mlx->win, 50, 25, RED,
		ft_itoa(t_mlx->g->step));
	mlx_string_put(t_mlx->mlx, t_mlx->win, 80, 25, RED, "ENEMY");
	mlx_string_put(t_mlx->mlx, t_mlx->win, 120, 25, RED,
		ft_itoa(t_mlx->g->collect_count));
	if (t_mlx->g->collect_count == 0)
		door_open(t_mlx);
	if (t_mlx->g->exit_count == 0)
		game_over(t_mlx, SUCCEED);
	return (0);
}

// void	printGraph(t_graph *graph)
// {
// 	int		v;
// 	t_node	*temp;

// 	for (v = 0; v < graph->num_vertex; v++)
// 	{
// 		temp = graph->adj_lsts[v];
// 		printf("\n Vertex %d\n: ", v);
// 		while (temp)
// 		{
// 			printf("%d -> ", *(int *)temp->content);
// 			temp = temp->next;
// 		}
// 		printf("\n");
// 	}
// }

// void printMap(char **map,int size, int x)
// {
// 	int i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		//printf("i : %d\n", i);
// 		printf("%c", map[i / x][i % x]);fflush(stdout);
// 		if(i % x == x-1)
// 			printf("\n");fflush(stdout);
// 		i ++;
// 	}
// 	printf("-------finished-------\n");fflush(stdout);
// }

// static void print_lst(t_node *adj_lst)
// {
// 	printf("----adj_list----\n");
// 	while(adj_lst)
// 	{
// 		printf("%d->", *(int *)adj_lst->content);
// 		adj_lst = adj_lst->next;
// 	}
// 	printf("\n");
// }

// static void obj_show(t_node *obj)
// {
// 	while (obj != NULL)
// 	{
// 		printf("obj : %d\n", *(int *)obj->content);fflush(stdout);
// 		obj = obj->next;
// 	}
// }
