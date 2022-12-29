/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:57:38 by wchen             #+#    #+#             */
/*   Updated: 2022/12/28 19:58:14 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_mlx	*t_mlx;

	t_mlx = mlx_initial(argc, argv);
	mlx_key_hook(t_mlx->win, key_hook, t_mlx);
	mlx_loop_hook(t_mlx->mlx, my_loop, t_mlx);
	mlx_hook(t_mlx->win, 17, 1L << 17, destroy_hook, t_mlx);
	mlx_loop(t_mlx->mlx);
	return (0);
}
