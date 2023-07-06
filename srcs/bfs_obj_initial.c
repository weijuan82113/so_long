/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_obj_initial.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:44:34 by wchen             #+#    #+#             */
/*   Updated: 2023/07/01 13:14:38 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	obj_push(t_game_board *g, int i)
{
	int	*content;

	content = malloc(sizeof(int));
	*content = i;
	if (!content)
		exit(EXIT_FAILURE);
	if (g->judge_obj == NULL)
		g->judge_obj = ft_lstnew(content);
	else
		ft_lstadd_back(&g->judge_obj, ft_lstnew(content));
}

void	bfs_obj_initial(t_game_board *g, char obj, int i)
{
	if (obj == 'P')
		g->position = i;
	else if (obj == 'E')
		g->goal_position = i;
	else if (obj == 'C')
		obj_push(g, i);
}
