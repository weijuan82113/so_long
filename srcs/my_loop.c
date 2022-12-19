/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:50:18 by wchen             #+#    #+#             */
/*   Updated: 2022/12/20 01:33:23 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static int position_judge(int enemy, int player)
{
	if (enemy < player)
		return (1);
	else
		return (0);
}

static void move_to(int direct, t_game_board *g, t_node *enemy)
{
	t_node	*adj_lst;
	int		p;
	int		move_p;

	p = *(int *)enemy->content;
	if (p == 0)
		return;
	//printGraph(g->graph);fflush(stdout);
	adj_lst = g->graph->adj_lsts[p];
	if (direct == ASC)
		ft_lst_ascsort(&adj_lst);
	else
		ft_lst_descsort(&adj_lst);
	move_p = *(int *)adj_lst->content;
	if(g->map[move_p / g->x][move_p % g->x] != '0')
		return;
	// printf("p is %d \n", p);fflush(stdout);
	// printf("move_p is %d \n", move_p);fflush(stdout);
	//printf("--before--\n");
	//printMap(g->map, g->x * g->y, g->x);
	g->map[move_p / g->x][move_p % g->x] = 'C';
	g->map[p / g->x][p % g->x] = '0';
	//printf("--after--\n");
	//printMap(g->map, g->x * g->y, g->x);
	*(int *)enemy->content = move_p;
}

// static void obj_show(t_node *obj)
// {
// 	while (obj != NULL)
// 	{
// 		printf("obj : %d\n", *(int *)obj->content);fflush(stdout);
// 		obj = obj->next;
// 	}
// }

static void enemy_move(t_mlx *t_mlx)
{
	t_node		*enemy;

	enemy = t_mlx->g->judge_obj;
	//obj_show(enemy);
	while(enemy != NULL)
	{
		// /printf("enemy position %d\n", *(int *)enemy->content);
		if(position_judge(*(int *)enemy->content, t_mlx->g->position))
			move_to(ASC, t_mlx->g, enemy);
		else
			move_to(DESC, t_mlx->g, enemy);
		enemy = enemy->next;
	}
	usleep(400000);
}

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

static void attack_animation(t_mlx *t_mlx)
{
	t_img	*sprite;
	int		p;
	void	*s_img;
	t_game_board *g;

	sprite = t_mlx->img_sprite;
	p = t_mlx->g->position;
	g = t_mlx->g;
	while(sprite != NULL)
	{
		//printf("sprite is %p\n", sprite);
		//printf("p is %d\n", p);
		//printf("g is %p\n", g);
		s_img = sprite->img;
		//printf("s_img is %p\n", s_img);
		//t_mlx->img_head->img = s_img;
		mlx_put_image_to_window(t_mlx->mlx, t_mlx->win, s_img, (p % g->x) * g->size,
			(p / g->x) * g->size);
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
	//win_initial(t_mlx->mlx, t_mlx->win, t_mlx->g, t_mlx->img_head);
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
