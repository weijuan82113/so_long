/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:10:15 by wchen             #+#    #+#             */
/*   Updated: 2022/12/19 23:34:44 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*sprite_lstnew(void *mlx, char object, int size)
{
	t_img	*img_head;

	img_head = malloc(sizeof(t_img));
	if (!img_head)
		exit(EXIT_FAILURE);
	// printf("object is %c", object);
	if (object == P1)
		img_head->img_path = ft_strjoin(P1_PATH, ft_itoa(size));
	else if (object == P2)
		img_head->img_path = ft_strjoin(P2_PATH, ft_itoa(size));
	else if (object == P3)
		img_head->img_path = ft_strjoin(P3_PATH, ft_itoa(size));
	img_head->obj = 'P';
	// printf("path is %s\n", img_head->img_path);
	img_head->img = mlx_xpm_file_to_image(mlx, img_head->img_path, &img_head->w,
			&img_head->h);
	img_head->next = NULL;
	return (img_head);
}
