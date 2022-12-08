/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:30:12 by wchen             #+#    #+#             */
/*   Updated: 2022/12/09 01:39:55 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static t_img	*img_initial(void *mlx, t_game_board *g)
{
	char 	*object;
	t_img	*img_head;

	object = "PEC01";
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

void mlx_initial(t_game_board *g)
{
	void	*mlx;
	void	*win;
	t_img	*img_head;

	mlx = mlx_init();
	win = mlx_new_window(mlx, g -> x * g -> size, g -> y * g -> size, "SO_LONG");
	img_head = img_initial(mlx, g);
	win_initial(mlx, win, g, img_head);
	while(img_head != NULL)
	{
		printf("the char is %c\n", img_head -> obj);
		img_head = img_head -> next;
	}
	mlx_loop(mlx);
}
