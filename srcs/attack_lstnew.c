/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:10:15 by wchen             #+#    #+#             */
/*   Updated: 2022/12/30 14:11:33 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*attack_lstnew(void *mlx, char object, char* size)
{
	t_img	*img_head;

	img_head = malloc(sizeof(t_img));
	if (!img_head)
		exit(EXIT_FAILURE);
	if (object == A1)
		img_head->img_path = ft_strjoin(A1_PATH, size);
	else if (object == A2)
		img_head->img_path = ft_strjoin(A2_PATH, size);
	else if (object == A3)
		img_head->img_path = ft_strjoin(A3_PATH, size);
	else if (object == A4)
		img_head->img_path = ft_strjoin(A3_PATH, size);
	img_head->obj = 'A';
	img_head->img = mlx_xpm_file_to_image(mlx, img_head->img_path, &img_head->w,
			&img_head->h);
	img_head->next = NULL;
	return (img_head);
}
