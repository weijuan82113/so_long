/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_valiation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:09:29 by wchen             #+#    #+#             */
/*   Updated: 2022/12/11 23:03:17 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_validation(t_game_board *g, char input_chr, int i)
{
	if (i / g->x == 0 || i / g->x == g->y - 1
		|| i % g->x == 0 || i % g->x == g->x - 1)
	{
		if (input_chr != '1')
			ft_error(WALL_ERR);
	}
}
