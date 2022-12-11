/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:04:56 by wchen             #+#    #+#             */
/*   Updated: 2022/12/11 23:27:54 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_validation(t_game_board *g_board)
{
	if (g_board->collect_count == 0)
		ft_error(COLLECTIBLE_ERR);
	else if (g_board->exit_count != 1)
		ft_error(EXIT_ERR);
	else if (g_board->player_count != 1)
		ft_error(PLAYER_ERR);
	else if (g_board->empty_count == 0)
		ft_error(EMPTY_ERR);
	else if (g_board->wall_count == 0)
		ft_error(NO_WALL_ERR);
	else if (g_board->y == 1 || g_board->x == 1)
		ft_error(ONE_LINE_ERR);
	if (g_board->x * 32 > 1920 || g_board->y * 32 > 1080)
		ft_error(MAP_SIZE_ERR);
	else if (g_board->x * 64 > 1920 || g_board->y * 64 > 1080)
		g_board->size = 32;
	else
		g_board->size = 64;
}
