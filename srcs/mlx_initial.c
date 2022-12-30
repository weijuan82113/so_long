/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:30:12 by wchen             #+#    #+#             */
/*   Updated: 2022/12/30 14:03:06 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	*img_initial(void *mlx, t_game_board *g)
{
	char	*object;
	char	*size;
	t_img	*img_head;

	object = "PCE01GK";
	size = ft_itoa(g->size);
	img_head = NULL;
	while (*object)
	{
		if (*object == 'P')
			img_head = img_lstnew(mlx, *object, size);
		else
			img_lstadd_back(&img_head, img_lstnew(mlx, *object, size));
		object++;
	}
	free(size);
	return (img_head);
}

static t_img	*sprite_initial(void *mlx, t_game_board *g)
{
	char	*object;
	char	*size;
	t_img	*img_head;

	object = "123";
	size = ft_itoa(g->size);
	img_head = NULL;
	while (*object)
	{
		if (*object == P1)
			img_head = sprite_lstnew(mlx, *object, size);
		else
			img_lstadd_back(&img_head, sprite_lstnew(mlx, *object, size));
		object++;
	}
	free(size);
	return (img_head);
}

static t_img	*die_initial(void *mlx, t_game_board *g)
{
	char	*object;
	char	*size;
	t_img	*img_head;

	object = "456";
	size = ft_itoa(g->size);
	img_head = NULL;
	while (*object)
	{
		if (*object == D1)
			img_head = die_lstnew(mlx, *object, size);
		else
			img_lstadd_back(&img_head, die_lstnew(mlx, *object, size));
		object++;
	}
	free(size);
	return (img_head);
}

static t_img	*enemy_attack_initial(void *mlx, t_game_board *g)
{
	char	*object;
	char	*size;
	t_img	*img_head;

	object = "789A";
	size = ft_itoa(g->size);
	img_head = NULL;
	while (*object)
	{
		if (*object == A1)
			img_head = attack_lstnew(mlx, *object, size);
		else
			img_lstadd_back(&img_head, attack_lstnew(mlx, *object, size));
		object++;
	}
	free(size);
	return (img_head);
}

t_mlx	*mlx_initial(int argc, char **argv)
{
	t_mlx	*t_mlx;

	t_mlx = malloc(sizeof(*t_mlx));
	if (!t_mlx)
		exit(EXIT_FAILURE);
	t_mlx->g = map_initial(argc, argv);
	t_mlx->mlx = mlx_init();
	if (!t_mlx->mlx)
		exit(EXIT_FAILURE);
	t_mlx->win = mlx_new_window(t_mlx->mlx, t_mlx->g->x * t_mlx->g->size,
			t_mlx->g->y * t_mlx->g->size, "SO_LONG");
	t_mlx->img_head = img_initial(t_mlx->mlx, t_mlx->g);
	t_mlx->img_sprite = sprite_initial(t_mlx->mlx, t_mlx->g);
	t_mlx->img_die = die_initial(t_mlx->mlx, t_mlx->g);
	t_mlx->img_attack = enemy_attack_initial(t_mlx->mlx, t_mlx->g);
	return (t_mlx);
}
