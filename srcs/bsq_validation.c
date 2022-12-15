/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:55:14 by wchen             #+#    #+#             */
/*   Updated: 2022/12/16 01:15:06 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bfs(t_graph *graph, int start)
{
	t_bfs	bfs;

	bfs.q = ft_create_queue();
	graph->visited[start] = 1;
	bfs.start_vertex = malloc(sizeof(int));
	*bfs.start_vertex = start;
	ft_enqueue(bfs.q, bfs.start_vertex);
	while (bfs.q->rear != NULL)
	{
		bfs.current_vertex = *(int *)bfs.q->front->content;
		bfs.temp = graph->adj_lsts[bfs.current_vertex];
		while (bfs.temp)
		{
			bfs.adj_vertex = malloc(sizeof(int));
			bfs.adj_vertex = bfs.temp->content;
			if (graph->visited[*bfs.adj_vertex] == 0)
			{
				graph->visited[*bfs.adj_vertex] = 1;
				ft_enqueue(bfs.q, bfs.adj_vertex);
			}
			bfs.temp = bfs.temp->next;
		}
		ft_dequeue(bfs.q);
	}
}

void	is_playable(t_node *obj, int *visited)
{
	while (obj != NULL)
	{
		if (visited[*(int *)obj->content] != 1)
			ft_error(ISPLAYED_ERR);
		obj = obj->next;
	}
}

void	bsq_validation(t_game_board *g)
{
	t_graph	*graph;
	char	**map;

	map = g->map;
	graph = graph_create(g->x * g->y, map, g->x);
	edge_initial(graph, g);
	bfs(graph, g->position);
	is_playable(g->judge_obj, graph->visited);
}
// Print the graph
// void printGraph(t_graph *graph) {
//   int v;
//   for (v = 0; v < graph->num_vertex; v++) {
//     t_node *temp = graph->adj_lsts[v];
//     printf("\n Vertex %d\n: ", v);
//     while (temp)
// 	{
//       printf("%d -> ", *(int *)temp->content);
//       temp = temp->next;
//     }
//     printf("\n");
//   }
// }
