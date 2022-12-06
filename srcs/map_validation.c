/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:04:56 by wchen             #+#    #+#             */
/*   Updated: 2022/12/06 23:09:24 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	map_validation(t_game_board *g_board)
{
	printf("C %d\n", g_board -> collect_count);
	printf("E %d\n", g_board -> exit_count);
	printf("P %d\n", g_board -> player_count);
	printf("0 %d\n", g_board -> empty_count);
	printf("1 %d\n", g_board -> wall_count);

	if (g_board -> collect_count == 0)
		ft_error(COLLECTIBLE_ERR);
	else if (g_board -> exit_count != 1)
		ft_error(EXIT_ERR);
	else if (g_board -> player_count != 1)
		ft_error(PLAYER_ERR);
	else if (g_board -> empty_count == 0)
		ft_error(EMPTY_ERR);
	else if (g_board -> wall_count == 0)
		ft_error(NO_WALL_ERR);
	else if (g_board -> y == 1 || g_board -> x == 1)
		ft_error(ONE_LINE_ERR);
}
