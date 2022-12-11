/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_initial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:32:13 by wchen             #+#    #+#             */
/*   Updated: 2022/12/11 23:08:48 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*find_img(t_img *img_head, char object)
{
	while (img_head)
	{
		if (img_head->obj == object)
			break ;
		img_head = img_head->next;
	}
	return (img_head->img);
}

void	win_initial(void *mlx, void *win, t_game_board *g, t_img *img_head)
{
	char	**map;
	void	*img;
	int		i;

	map = g->map;
	i = 0;
	while (i < g->x * g->y)
	{
		img = find_img(img_head, map[i / g->x][i % g->x]);
		mlx_put_image_to_window(mlx, win, img, (i % g->x) * g->size,
			(i / g->x) * g->size);
		i++;
	}
}
