/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:08:26 by wchen             #+#    #+#             */
/*   Updated: 2022/12/28 15:48:46 by wchen            ###   ########.fr       */
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

	(void) t_mlx;
	while (img_head != NULL)
	{
		temp = img_head->next;
		if (img_head->img != NULL)
		{
			mlx_destroy_image(t_mlx->mlx, img_head->img);
			free(img_head->img_path);
		}
		free(img_head);
		img_head = NULL;
		img_head = temp;
	}
}

void	free_all(t_mlx *t_mlx)
{
	printf("test1\n");fflush(stdout);
	if (t_mlx->img_head != NULL)
		free_img(t_mlx, t_mlx->img_head);
	printf("test2\n");fflush(stdout);
	if (t_mlx->img_sprite != NULL)
		free_img(t_mlx, t_mlx->img_sprite);
	mlx_clear_window(t_mlx->mlx, t_mlx->win);
	mlx_destroy_window(t_mlx->mlx, t_mlx->win);
	mlx_destroy_display(t_mlx->mlx);
	printf("test3\n");fflush(stdout);
	if (t_mlx->mlx != NULL)
	{
		free(t_mlx->mlx);
		t_mlx->mlx = NULL;
	}
	printf("test4\n");fflush(stdout);
	if (t_mlx->g != NULL)
		free_g_board(t_mlx->g);
	printf("test5\n");fflush(stdout);
	free(t_mlx);
	printf("test6\n");fflush(stdout);
	t_mlx = NULL;
}
