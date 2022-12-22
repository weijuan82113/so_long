#include "so_long.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q so_long");
}

int main(void)
{
	t_img	*img_head;
	void	*mlx;
	int		size;
	char	*itoa;

	mlx = mlx_init();
	img_head = malloc(sizeof(t_img));
	img_head->obj = 'P';
	size = 32;
	itoa = ft_itoa(size);
	img_head->img_path = ft_strjoin(PL_PATH, itoa);
	img_head->img = mlx_xpm_file_to_image(mlx, img_head->img_path, &img_head->w,
			&img_head->h);
	mlx_destroy_image(mlx, img_head->img);
	free(itoa);
	free(img_head->img_path);
	free(img_head);
	free(mlx);
}
