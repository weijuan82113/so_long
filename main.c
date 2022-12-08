/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:57:38 by wchen             #+#    #+#             */
/*   Updated: 2022/12/08 23:14:28 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int main(int argc, char **argv)
{
	t_game_board	*g_board;

	g_board = NULL;
	g_board = map_initial(argc, argv, g_board);
	mlx_initial(g_board);

	return (0);
}
