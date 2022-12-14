/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:55:14 by wchen             #+#    #+#             */
/*   Updated: 2022/12/14 20:51:19 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// int bsq()
// {
// 	if(goal_vertex == NULL)
// 		return(1)
// 	if(is_empty())
// 		return(0)

// }

void	bsq_validation(t_game_board *g)
{
	t_node *head;

	head = g->goal_vertex;
	while (head != NULL)
	{
		printf("vertex is %d\n", *(int*)head->content);fflush(stdout);
		head = head -> next;
	}

	// char 	**map;
	// int 	i;

	//goal_vertex(lst)
	//char ** vertex_inital()
	//is_visted(,)
	//is_empty()
	//strat_position(int)
	//confirm_visted()

	// if (is_vis)

}
