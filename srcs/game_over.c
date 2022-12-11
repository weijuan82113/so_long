/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:57:21 by wchen             #+#    #+#             */
/*   Updated: 2022/12/11 23:27:45 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_mlx *t_mlx, char *exit_msg)
{
	mlx_clear_window(t_mlx->mlx, t_mlx->win);
	mlx_destroy_window(t_mlx->mlx, t_mlx->win);
	ft_printf(exit_msg);
	free_all(t_mlx);
	exit(EXIT_SUCCESS);
}
