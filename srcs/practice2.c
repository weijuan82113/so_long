/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:24:37 by wchen             #+#    #+#             */
/*   Updated: 2022/12/05 19:13:27 by wchen            ###   ########.fr       */
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
	void	*img3;
	void	*img4;
	void	*img5;
	void	*win;
	char	*relative_path1 = "./images/empty64_64.xpm";
	char	*relative_path2 = "./images/player64_64.xpm";
	char	*relative_path3 = "./images/exit64_64.xpm";
	char	*relative_path4 = "./images/wall64_64.xpm";
	char	*relative_path5 = "./images/collectible64_64.xpm";
	int		img_width;
	int		img_height;
	int		x,y;

	mlx = mlx_init();
	img1 = mlx_xpm_file_to_image(mlx, relative_path1, &img_width, &img_height);
	printf("img1 width is %d, height is %d\n",img_width,img_height);fflush(stdout);
	printf("img1 is %p\n",img1);
	img2 = mlx_xpm_file_to_image(mlx, relative_path2, &img_width, &img_height);
	printf("img2 width is %d, height is %d\n",img_width,img_height);fflush(stdout);
	printf("img2 is %p\n",img2);
	img3 = mlx_xpm_file_to_image(mlx, relative_path3, &img_width, &img_height);
	printf("img3 width is %d, height is %d\n",img_width,img_height);fflush(stdout);
	printf("img3 is %p\n",img3);
	img4 = mlx_xpm_file_to_image(mlx, relative_path4, &img_width, &img_height);
	printf("img4 width is %d, height is %d\n",img_width,img_height);fflush(stdout);
	printf("img4 is %p\n",img4);
	img5 = mlx_xpm_file_to_image(mlx, relative_path5, &img_width, &img_height);
	printf("img5 width is %d, height is %d\n",img_width,img_height);fflush(stdout);
	printf("img5 is %p\n",img5);
	mlx_new_image(mlx,64,64);
	win = mlx_new_window(mlx, 960, 540, "Hello world!");
	x = 0;
	y = 0;
	while(y*64 <= 540)
	{
		while (x*64 <= 960)
		{
			mlx_put_image_to_window(mlx, win, img1, x*64, y*64);
			x ++;
		}
		x = 0;
		mlx_do_sync(mlx);
		y ++;
	}
	mlx_put_image_to_window(mlx, win, img2, 64, 64);
	mlx_put_image_to_window(mlx, win, img3, 256, 128);
	mlx_put_image_to_window(mlx, win, img4, 320, 128);
	mlx_put_image_to_window(mlx, win, img5, 384, 128);
	sleep(1);
	mlx_put_image_to_window(mlx, win, img1, 64, 64);
	mlx_put_image_to_window(mlx, win, img2, 128, 64);
	sleep(1);
	mlx_put_image_to_window(mlx, win, img1, 128, 64);
	mlx_put_image_to_window(mlx, win, img2, 192, 64);
	//mlx_destroy_image(mlx, img2);
	mlx_do_sync(mlx);
	//mlx_put_image_to_window(mlx, win, img2, 64, 0);
	// mlx_do_sync(mlx);
	mlx_loop(mlx);
}
