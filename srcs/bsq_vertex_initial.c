/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_vertex_initial.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:44:34 by wchen             #+#    #+#             */
/*   Updated: 2022/12/14 20:44:43 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void vertex_push(t_game_board *g, int i)
{
	int *content;

	content = malloc(sizeof(int) * 1);
	*content = i;
	if(!content)
		exit(EXIT_FAILURE);
	if (g->goal_vertex == NULL)
		g->goal_vertex = ft_lstnew(content);
	else
		ft_lstadd_back(&g->goal_vertex, ft_lstnew(content));
}


void bsq_vertex_intial(t_game_board *g, char obj, int i)
{
	if (obj == 'P')
		g->position = i;
	if (obj == 'C' || obj == 'E')
		vertex_push(g, i);
}
