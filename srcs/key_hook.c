/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:54:33 by wchen             #+#    #+#             */
/*   Updated: 2022/12/10 03:30:06 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

// int render_next_frame(t_mlx *t_mlx)
// {
// 	mlx_put_image_to_window(t_mlx -> mlx, t_mlx -> win, t_mlx -> img_head -> img, 0 , 0);
// 	return (0);
// }

// static void move_up(t_mlx *t_mlx)
// {
// 	mlx_loop_hook(t_mlx -> mlx, render_next_frame, t_mlx);
// }

// int	player_initial(t_game_board *g)
// {
// 	int 	i;
// 	char	**map;

// 	map = g -> map;
// 	i = 0;
// 	while(map[i / g->x][i % g->x])
// 	{
// 		if (map[i / g->x][i % g->x] == 'P')
// 			break;
// 		i ++;
// 	}
// 	return (i);
// }

int move_judge(t_game_board *g, int direct)
{
	char	**map;
	int		p;
	int		move_p;

	p = g -> position;
	map = g -> map;
	if(direct == UP)
		move_p = p - g -> x;
	if(direct == DOWN)
		move_p = p + g -> x;
	if(direct == LEFT)
		move_p = p - 1;
	if(direct == RIGHT)
		move_p = p + 1;
	if(map[move_p / g -> x][move_p % g->x] == '1')
		return (0);
	else if (map[move_p / g -> x][move_p % g -> x] == 'E' && g -> collect_count != 0)
		return (0);
	else if (map[move_p / g -> x][move_p % g -> x] == 'C')
		g -> collect_count --;
	return (1);
}

void player_move(t_mlx *t_mlx,t_game_board *g, int direct)
{
	void	*img_p;
	void	*img_e;
	int		p;
	int		move_p;
	int		size;

	p = g -> position;
	size = g -> size;
	if(direct == UP)
		move_p = p - g -> x;
	if(direct == DOWN)
		move_p = p + g -> x;
	if(direct == LEFT)
		move_p = p - 1;
	if(direct == RIGHT)
		move_p = p + 1;
	img_p = t_mlx -> img_head -> img;
	img_e = t_mlx -> img_head -> next -> img;
	mlx_put_image_to_window(t_mlx -> mlx, t_mlx -> win, img_e, (p % g -> x) * size, (p / g -> x) * size);
	mlx_put_image_to_window(t_mlx -> mlx, t_mlx -> win, img_p, (move_p % g -> x) * size,(move_p / g -> x) * size);
	g -> position = move_p;
}

int	key_hook(int keycode, t_mlx *t_mlx)
{
	printf("t_mlx is %p\n", t_mlx);
	printf("keycode is %d\n", keycode);
	printf("position is %d\n", t_mlx -> g -> position);
	t_game_board *g;

	g = t_mlx -> g;
	if(keycode == KEY_UP || keycode == KEY_W)
	{
		printf("up\n");
		if(move_judge(g, UP))
			player_move(t_mlx, g, UP);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		printf("down\n");
		if(move_judge(g, DOWN))
			player_move(t_mlx, g, DOWN);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		printf("left\n");
		if(move_judge(g, LEFT))
			player_move(t_mlx, g, LEFT);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		printf("right\n");
		if(move_judge(g, RIGHT))
			player_move(t_mlx, g, RIGHT);
	}
	else if (keycode == ESC)
		printf("ESC\n");
	return(0);
}
