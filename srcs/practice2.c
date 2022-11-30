/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:24:37 by wchen             #+#    #+#             */
/*   Updated: 2022/11/23 23:48:00 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>


#define MLX_SYNC_IMAGE_WRITABLE		1
#define MLX_SYNC_WIN_FLUSH_CMD		2
#define MLX_SYNC_WIN_CMD_COMPLETED	3

int	main(void)
{
	void	*mlx;
	void	*img1;
	void	*img2;
	void	*win;
	char	*relative_path1 = "./images/sprites/Ghosts/B/ghost_down1.xpm";
	char	*relative_path2 = "./images/sprites/Ghosts/B/ghost_down2.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img1 = mlx_xpm_file_to_image(mlx, relative_path1, &img_width, &img_height);
	printf("img1 width is %d, height is %d\n",img_width,img_height);fflush(stdout);
	img2 = mlx_xpm_file_to_image(mlx, relative_path2, &img_width, &img_height);
	printf("img2 width is %d, height is %d\n",img_width,img_height);;fflush(stdout);
	win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_put_image_to_window(mlx, win, img1, 0, 0);
	mlx_do_sync(mlx);
	free(img1);
	sleep(3);
	mlx_put_image_to_window(mlx, win, img2, 0, 0);
	mlx_do_sync(mlx);
	mlx_loop(mlx);
}
