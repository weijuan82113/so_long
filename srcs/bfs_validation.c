/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:55:14 by wchen             #+#    #+#             */
/*   Updated: 2022/12/20 22:05:54 by wchen            ###   ########.fr       */
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
	free(bfs.q);
}

void	is_playable(t_game_board *g, int *visited)
{
	t_node	*obj;

	obj = g->judge_obj;
	printf("goal is %d\n", g->goal_position);fflush(stdout);
	if (visited[g->goal_position] != 1)
		ft_error(ACHIEVE_ERR);
	while (obj != NULL)
	{
		if (visited[*(int *)obj->content] != 1)
			ft_error(COLLECTABLE_ERR);
		obj = obj->next;
	}
}

void	bfs_validation(t_game_board *g)
{
	g->graph = graph_create(g->x * g->y, g->map, g->x);
	edge_initial(g->graph, g);
	bfs(g->graph, g->position);
	is_playable(g, g->graph->visited);
	//free_graph(graph, g);
}
//Print the graph
// void	printGraph(t_graph *graph)
// {
// 	int		v;
// 	t_node	*temp;

// 	for (v = 0; v < graph->num_vertex; v++)
// 	{
// 		temp = graph->adj_lsts[v];
// 		printf("\n Vertex %d\n: ", v);
// 		while (temp)
// 		{
// 			printf("%d -> ", *(int *)temp->content);
// 			temp = temp->next;
// 		}
// 		printf("\n");
// 	}
// }

// void printMap(int *visited,int size, int x)
// {
// 	int i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		//printf("i : %d\n", i);
// 		printf("%d", visited[i]);fflush(stdout);
// 		if(i % x == x-1)
// 			printf("\n");fflush(stdout);
// 		i ++;
// 	}
// 	printf("-------finished-------\n");fflush(stdout);
// }
