/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:07:31 by wchen             #+#    #+#             */
/*   Updated: 2022/12/06 22:39:25 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int object_validation(char input_chr, t_game_board *g_board)
{
	if (input_chr == 'C')
		g_board -> collect_count ++;
	else if (input_chr == 'E')
		g_board -> 	exit_count ++;
	else if (input_chr == 'P')
		g_board -> player_count ++;
	else if (input_chr == '0')
		g_board -> empty_count ++;
	else if (input_chr == '1')
		g_board -> wall_count ++;
	else if (1)
		return (1);
	return (0);
}
