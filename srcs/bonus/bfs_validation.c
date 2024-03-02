/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:55:14 by wchen             #+#    #+#             */
/*   Updated: 2024/02/08 20:18:40 by wchen            ###   ########.fr       */
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
			if (graph->visited[*(int *)bfs.temp->content] == 0)
			{
				bfs.adj_vertex = malloc(sizeof(int));
				*bfs.adj_vertex = *(int *)bfs.temp->content;
				graph->visited[*bfs.adj_vertex] = 1;
				ft_enqueue(bfs.q, bfs.adj_vertex);
			}
			bfs.temp = bfs.temp->next;
		}
		ft_dequeue(bfs.q);
	}
	free(bfs.q);
}

void	is_collectable(t_game_board *g, int *visited)
{
	t_node	*obj;

	visited[g->goal_position] = 1;
	bfs(g->graph, g->position);
	obj = g->judge_obj;
	while (obj != NULL)
	{
		if (visited[*(int *)obj->content] != 1)
			ft_error(COLLECTABLE_ERR);
		obj = obj->next;
	}
}

void	reset_visited(t_game_board *g)
{
	int			i;
	t_graph		*graph;
	char		**map;

	i = 0;
	graph = g->graph;
	map = g->map;
	while (i < graph->num_vertex)
	{
		if (map[i / g->x][i % g->x] != '1')
			graph->visited[i] = 0;
		i ++;
	}
}

void	is_achievable(t_game_board *g, int *visited)
{
	reset_visited(g);
	bfs(g->graph, g->position);
	if (visited[g->goal_position] != 1)
		ft_error(ACHIEVE_ERR);
}

//Print the graph
void	printGraph(t_graph *graph)
{
	int		v;
	t_node	*temp;

	for (v = 0; v < graph->num_vertex; v++)
	{
		temp = graph->adj_lsts[v];
		printf("\n Vertex %d\n: ", v);
		while (temp)
		{
			printf("%d -> ", *(int *)temp->content);
			temp = temp->next;
		}
		printf("\n");
	}
}

void printMap(int *visited,int size, int x)
{
	int i;

	i = 0;
	while (i < size)
	{
		//printf("i : %d\n", i);
		printf("%d", visited[i]);fflush(stdout);
		if(i % x == x-1)
			printf("\n");fflush(stdout);
		i ++;
	}
	printf("-------finished-------\n");fflush(stdout);
}

void	bfs_validation(t_game_board *g)
{
	g->graph = graph_create(g->x * g->y, g->map, g->x);
	edge_initial(g->graph, g);
	printGraph(g->graph);
	is_collectable(g, g->graph->visited);
	is_achievable(g, g->graph->visited);
}

