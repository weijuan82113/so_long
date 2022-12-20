/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:08:26 by wchen             #+#    #+#             */
/*   Updated: 2022/12/20 22:43:55 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_g_board(t_game_board *g)
{
	char	**map;

	map = g->map;
	if (g->map_head != NULL)
		ft_lstclear(&(g->map_head), free);
	if (g->judge_obj != NULL)
		ft_lstclear(&(g->judge_obj), free);
	if (map != NULL)
	{
		while (*map != NULL)
		{
			free(*map);
			map++;
		}
		free(*map);
		free(g->map);
	}
	if (g->graph != NULL)
		free_graph(g->graph);
	free(g);
	g = NULL;
}

static void	free_img(t_mlx *t_mlx, t_img *img_head)
{
	t_img	*temp;

	while (img_head != NULL)
	{
		temp = img_head->next;
		if (img_head->img != NULL)
			mlx_destroy_image(t_mlx->mlx, img_head->img);
		free(img_head);
		img_head = NULL;
		img_head = temp;
	}
}

void	free_all(t_mlx *t_mlx)
{
	mlx_destroy_window(t_mlx->mlx, t_mlx->win);
	mlx_clear_window(t_mlx->mlx, t_mlx->win);
	if (t_mlx->img_head != NULL)
		free_img(t_mlx, t_mlx->img_head);
	if (t_mlx->img_sprite != NULL)
		free_img(t_mlx, t_mlx->img_sprite);
	if (t_mlx->mlx != NULL)
	{
		free(t_mlx->mlx);
		t_mlx->mlx = NULL;
	}
	if (t_mlx->g != NULL)
		free_g_board(t_mlx->g);
	free(t_mlx);
	t_mlx = NULL;
}
