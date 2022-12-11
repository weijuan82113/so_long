/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:50:18 by wchen             #+#    #+#             */
/*   Updated: 2022/12/11 20:55:02 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static void door_open(t_mlx *t_mlx)
{
	int	i;
	int x;
	int y;
	char **map;

	i = 0;
	x = t_mlx -> g -> x;
	y = t_mlx -> g -> y;
	map = t_mlx -> g -> map;
	// while (map[i / x][i % x] != 'E')
	// 	i ++;
	// map[i / x][i % x] = 'G';
	while(i <  x * y)
	{
		if (map[i / x][i % x] == 'E')
		{
			map[i / x][i % x] = 'G';
			break;
		}
		i ++;
	}
}

int	my_loop(t_mlx *t_mlx)
{
	win_initial(t_mlx -> mlx, t_mlx -> win, t_mlx -> g, t_mlx -> img_head);
	if (t_mlx -> g -> collect_count == 0)
		door_open(t_mlx);
	if (t_mlx -> g -> exit_count == 0)
		game_over(t_mlx, SUCCEED);
	return (0);
}