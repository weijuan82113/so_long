/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:10:15 by wchen             #+#    #+#             */
/*   Updated: 2022/12/30 16:00:19 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*img_lstnew(void *mlx, char object, char *size)
{
	t_img	*img_head;

	img_head = malloc(sizeof(t_img));
	if (!img_head)
		exit(EXIT_FAILURE);
	if (object == 'P')
		img_head->img_path = ft_strjoin(PL_PATH, size);
	else if (object == 'E')
		img_head->img_path = ft_strjoin(EX_PATH, size);
	else if (object == 'C')
		img_head->img_path = ft_strjoin(EN_PATH, size);
	else if (object == '1')
		img_head->img_path = ft_strjoin(WA_PATH, size);
	else if (object == '0')
		img_head->img_path = ft_strjoin(EM_PATH, size);
	else if (object == 'G')
		img_head->img_path = ft_strjoin(EO_PATH, size);
	else if (object == 'K')
		img_head->img_path = ft_strjoin(KL_PATH, size);
	img_head->obj = object;
	img_head->img = mlx_xpm_file_to_image(mlx, img_head->img_path, &img_head->w,
			&img_head->h);
	img_head->next = NULL;
	return (img_head);
}
