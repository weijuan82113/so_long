/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:54:33 by wchen             #+#    #+#             */
/*   Updated: 2022/12/30 15:10:37 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	enemy_kill(t_game_board *g, int enemy_p)
{
	t_node	*obj;
	char	**map;

	obj = g->judge_obj;
	map = g->map;
	map[enemy_p / g->x][enemy_p % g->x] = 'K';
	while (*(int *)obj->content != enemy_p)
		obj = obj->next;
	*(int *)obj->content = 0;
}

static void	player_attack(t_mlx *t_mlx)
{
	int		p;
	int		x;
	char	**map;

	p = t_mlx->g->position;
	x = t_mlx->g->x;
	map = t_mlx->g->map;
	t_mlx->g->attack = 1;
	if (map[(p - x) / x][(p - x) % x] == 'C')
		enemy_kill(t_mlx->g, p - x);
	if (map[(p + x) / x][(p + x) % x] == 'C')
		enemy_kill(t_mlx->g, p + x);
	if (map[(p - 1) / x][(p - 1) % x] == 'C')
		enemy_kill(t_mlx->g, p - 1);
	if (map[(p + 1) / x][(p + 1) % x] == 'C')
		enemy_kill(t_mlx->g, p + 1);
}

int	move_judge(t_game_board *g, int direct)
{
	int	p;
	int	move_p;

	p = g->position;
	if (direct == UP)
		move_p = p - g->x;
	if (direct == DOWN)
		move_p = p + g->x;
	if (direct == LEFT)
		move_p = p - 1;
	if (direct == RIGHT)
		move_p = p + 1;
	if (g->map[move_p / g->x][move_p % g->x] == 'G')
		g->exit_count--;
	else if (g->map[move_p / g->x][move_p % g->x] == 'K')
		g->collect_count--;
	else if (g->map[move_p / g->x][move_p % g->x] == 'C')
	{
		g->die = 1;
		return (0);
	}
	else if (g->map[move_p / g->x][move_p % g->x] != '0')
		return (0);
	return (1);
}

void	player_move(t_game_board *g, int direct)
{
	int	p;
	int	move_p;

	if (g->die == 1)
		return ;
	p = g->position;
	if (direct == UP)
		move_p = p - g->x;
	if (direct == DOWN)
		move_p = p + g->x;
	if (direct == LEFT)
		move_p = p - 1;
	if (direct == RIGHT)
		move_p = p + 1;
	g->map[move_p / g->x][move_p % g->x] = 'P';
	g->map[p / g->x][p % g->x] = '0';
	g->step++;
	ft_printf("The step count is %d\n", g->step);
	g->position = move_p;
}

int	key_hook(int keycode, t_mlx *t_mlx)
{
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		if (move_judge(t_mlx->g, UP))
			player_move(t_mlx->g, UP);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		if (move_judge(t_mlx->g, DOWN))
			player_move(t_mlx->g, DOWN);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		if (move_judge(t_mlx->g, LEFT))
			player_move(t_mlx->g, LEFT);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		if (move_judge(t_mlx->g, RIGHT))
			player_move(t_mlx->g, RIGHT);
	}
	else if (keycode == ESC || keycode == KEY_Q)
		game_over(t_mlx, GAME_OVER);
	else if (keycode == KEY_SPC)
		player_attack(t_mlx);
	return (0);
}
