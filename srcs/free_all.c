/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:08:26 by wchen             #+#    #+#             */
/*   Updated: 2022/12/11 23:03:46 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_g_board(t_game_board *g)
{
	char	**map;

	map = g->map;
	if (g->map_head != NULL)
		ft_lstclear(&(g->map_head), free);
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
	free(g);
	g = NULL;
}

static void	free_img(t_img *img_head)
{
	t_img	*temp_head;

	while (img_head != NULL)
	{
		temp_head = img_head->next;
		if (img_head->img != NULL)
			free(img_head->img);
		free(img_head);
		img_head = NULL;
		img_head = temp_head;
	}
}

void	free_all(t_mlx *t_mlx)
{
	if (t_mlx->mlx != NULL)
	{
		free(t_mlx->mlx);
		t_mlx->mlx = NULL;
	}
	if (t_mlx->img_head != NULL)
		free_img(t_mlx->img_head);
	if (t_mlx->g != NULL)
		free_g_board(t_mlx->g);
	free(t_mlx);
	t_mlx = NULL;
}
