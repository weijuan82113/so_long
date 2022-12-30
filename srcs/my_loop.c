/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:50:18 by wchen             #+#    #+#             */
/*   Updated: 2022/12/30 14:48:13 by wchen            ###   ########.fr       */
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
	t_mlx->g->attack = 0;
}

static void	e_attack_animation(t_mlx *t_mlx)
{
	t_img			*e_attack;
	int				ep;
	void			*s_img;
	t_game_board	*g;

	e_attack = t_mlx->img_attack;
	ep = t_mlx->g->e_position;
	g = t_mlx->g;
	printf("ep : %d\n", ep);fflush(stdout);
	while (e_attack != NULL)
	{
		s_img = e_attack->img;
		mlx_put_image_to_window(t_mlx->mlx, t_mlx->win, s_img, (ep % g->x)
			* g->size, (ep / g->x) * g->size);
		usleep(100000);
		e_attack = e_attack->next;
	}
	usleep(250000);
	t_mlx->g->e_attack = 0;
}

static void	die_animation(t_mlx *t_mlx)
{
	t_img			*die;
	int				p;
	void			*d_img;
	t_game_board	*g;

	die = t_mlx->img_die;
	p = t_mlx->g->position;
	g = t_mlx->g;
	while (die != NULL)
	{
		printf("test1\n");
		d_img = die->img;
		mlx_put_image_to_window(t_mlx->mlx, t_mlx->win, d_img, (p % g->x)
			* g->size, (p / g->x) * g->size);
		printf("test2\n");
		usleep(250000);
		die = die->next;
	}
	sleep(1);
	game_over(t_mlx, KILLED);
}

int	my_loop(t_mlx *t_mlx)
{
	char 			*step;
	char 			*enemy;
	t_game_board 	*g;

	g = t_mlx->g;
	g->frame ++;
	printf("e_attack %d\n", g->e_attack);
	if (g->e_attack == 1)
		e_attack_animation(t_mlx);
	else if (g->die == 1)
		die_animation(t_mlx);
	else if (g->attack == 1)
		attack_animation(t_mlx);
	else if(g->frame % enemy_frame == 0)
		enemy_move(t_mlx);
	win_initial(t_mlx->mlx, t_mlx->win, t_mlx->g, t_mlx->img_head);
	mlx_string_put(t_mlx->mlx, t_mlx->win, 10, 25, RED, "STEP");
	step = ft_itoa(t_mlx->g->step);
	mlx_string_put(t_mlx->mlx, t_mlx->win, 50, 25, RED, step);
	free(step);
	mlx_string_put(t_mlx->mlx, t_mlx->win, 80, 25, RED, "ENEMY");
	enemy = ft_itoa(t_mlx->g->collect_count);
	mlx_string_put(t_mlx->mlx, t_mlx->win, 120, 25, RED, enemy);
	free(enemy);
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
