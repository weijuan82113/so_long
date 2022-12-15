/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_obj_initial.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:44:34 by wchen             #+#    #+#             */
/*   Updated: 2022/12/16 01:15:30 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	obj_push(t_game_board *g, int i)
{
	int	*content;

	content = malloc(sizeof(int) * 1);
	*content = i;
	if (!content)
		exit(EXIT_FAILURE);
	if (g->judge_obj == NULL)
		g->judge_obj = ft_lstnew(content);
	else
		ft_lstadd_back(&g->judge_obj, ft_lstnew(content));
}

void	bsq_obj_initial(t_game_board *g, char obj, int i)
{
	if (obj == 'P')
		g->position = i;
	if (obj == 'C' || obj == 'E')
		obj_push(g, i);
}
