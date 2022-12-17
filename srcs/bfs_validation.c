/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:55:14 by wchen             #+#    #+#             */
/*   Updated: 2022/12/17 13:52:40 by wchen            ###   ########.fr       */
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
			*bfs.adj_vertex = *(int *)bfs.temp->content;
			if (graph->visited[*bfs.adj_vertex] == 0)
			{
				graph->visited[*bfs.adj_vertex] = 1;
				ft_enqueue(bfs.q, bfs.adj_vertex);
			}
			bfs.temp = bfs.temp->next;
		}
		ft_dequeue(bfs.q);
	}
	free (bfs.q);
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

void printGraph(t_graph *graph);

void	bfs_validation(t_game_board *g)
{
	t_graph	*graph;
	char	**map;

	map = g->map;
	graph = graph_create(g->x * g->y, map, g->x);
	edge_initial(graph, g);
	bfs(graph, g->position);
	//printGraph(graph);
	is_playable(g->judge_obj, graph->visited);
	free_graph(graph, g);
}
// Print the graph
void printGraph(t_graph *graph) {
  int v;
  for (v = 0; v < graph->num_vertex; v++) {
    t_node *temp = graph->adj_lsts[v];
    printf("\n Vertex %d\n: ", v);
    while (temp)
	{
      printf("%d -> ", *(int *)temp->content);
      temp = temp->next;
    }
    printf("\n");
  }
}
