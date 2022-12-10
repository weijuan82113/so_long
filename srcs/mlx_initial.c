/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:30:12 by wchen             #+#    #+#             */
/*   Updated: 2022/12/10 03:16:18 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static t_img	*img_initial(void *mlx, t_game_board *g)
{
	char 	*object;
	t_img	*img_head;

	object = "P0CE1";
	img_head = NULL;
	while (*object)
	{
		if (*object == 'P')
			img_head = img_lstnew(mlx, *object, g -> size);
		else
			img_lstadd_back(&img_head, img_lstnew(mlx, *object, g -> size));
		object ++;
	}
	return (img_head);
}

static void *find_img(t_img *img_head, char object)
{
	while (img_head)
	{
		if(img_head -> obj == object)
			break;
		img_head = img_head -> next;
	}
	return (img_head -> img);
}

static void win_initial(void *mlx, void *win, t_game_board *g, t_img *img_head)
{
	char	**map;
	void	*img;
	int		i;

	map = g -> map;
	i = 0;
	while (i < g -> x * g -> y)
	{
		img = find_img(img_head, map[i / g -> x][i % g -> x]);
		mlx_put_image_to_window(mlx, win, img, (i % g -> x) * g -> size, (i / g -> x) * g -> size);
		i ++;
	}
}

t_mlx	*mlx_initial(int argc, char **argv)
{
	t_mlx	*t_mlx;

	t_mlx = malloc(sizeof(*t_mlx));
	if(!t_mlx)
		exit(EXIT_FAILURE);
	t_mlx -> g = map_initial(argc, argv);
	t_mlx -> mlx = mlx_init();
	t_mlx -> win = mlx_new_window(t_mlx -> mlx, t_mlx -> g -> x * t_mlx -> g -> size, t_mlx -> g -> y * t_mlx -> g -> size, "SO_LONG");
	t_mlx -> img_head = img_initial(t_mlx -> mlx, t_mlx -> g);
	win_initial(t_mlx -> mlx, t_mlx -> win, t_mlx -> g, t_mlx -> img_head);
	return (t_mlx);
}
