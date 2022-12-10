/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:57:38 by wchen             #+#    #+#             */
/*   Updated: 2022/12/10 01:21:43 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int main(int argc, char **argv)
{
	t_mlx			*t_mlx;

	t_mlx = mlx_initial(argc, argv);
	mlx_key_hook(t_mlx -> win, key_hook, t_mlx);
	mlx_loop(t_mlx -> mlx);
	return (0);
}
