/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:57:38 by wchen             #+#    #+#             */
/*   Updated: 2022/12/13 21:26:42 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	*t_mlx;

	t_mlx = mlx_initial(argc, argv);
	mlx_key_hook(t_mlx->win, key_hook, t_mlx);
	mlx_loop_hook(t_mlx->mlx, my_loop, t_mlx);
	mlx_hook(t_mlx->win, 17, 1L << 17, destroy_hook, t_mlx);
	mlx_loop(t_mlx->mlx);
	//system("leaks -g so_long");
	return (0);
}
