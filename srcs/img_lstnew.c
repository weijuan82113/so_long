/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:10:15 by wchen             #+#    #+#             */
/*   Updated: 2022/12/09 01:42:57 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

t_img	*img_lstnew(void *mlx, char object,int size)
{
	t_img *img_head;

	img_head = malloc(sizeof(t_img));
	if (!img_head)
		exit(EXIT_FAILURE);
	if (object == 'P')
		img_head -> img_path = ft_strjoin(pl_path,ft_itoa(size));
	else if (object == 'E')
		img_head -> img_path = ft_strjoin(ex_path,ft_itoa(size));
	else if (object == 'C')
		img_head -> img_path = ft_strjoin(co_path,ft_itoa(size));
	else if (object == '1')
		img_head -> img_path = ft_strjoin(wa_path,ft_itoa(size));
	else if (object == '0')
		img_head -> img_path = ft_strjoin(em_path,ft_itoa(size));
	img_head -> obj = object;
	img_head -> img = mlx_xpm_file_to_image(mlx, img_head -> img_path, &img_head -> w, &img_head ->h);
	img_head -> next = NULL;
	return (img_head);
}
