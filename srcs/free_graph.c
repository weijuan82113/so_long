/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:46:53 by wchen             #+#    #+#             */
/*   Updated: 2022/12/17 12:43:19 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//Print the graph
// void printGraph(t_graph *graph, int v)
// {
//     t_node *temp = graph->adj_lsts[v];
//     printf("\n Vertex %d\n: ", v);
// 	printf("\n adj_lsts[%d] : %p \n",v, graph->adj_lsts[v]);
//     while (temp)
// 	{
//       printf("%d -> ", *(int *)temp->content);
//       temp = temp->next;
//     }
//     printf("\n");
// }

void	free_graph(t_graph *graph, t_game_board *g)
{
	int	i;

	i = 0;
	while(i < g->x * g->y)
	{
		//debug_point
		//printGraph(graph, i);fflush(stdout);
		if (graph->adj_lsts[i] != NULL)
			ft_lstclear(&(graph->adj_lsts[i]), free);
		i ++;
	}
	free(graph->adj_lsts);
	free(graph->visited);
	free(graph);
}
