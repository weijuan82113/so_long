/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:55:14 by wchen             #+#    #+#             */
/*   Updated: 2022/12/15 22:40:06 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int bfs(t_graph *graph, int start)
{
	t_queue	*q;

	q = ft_create_queue();
	graph->visited[start] = 1;

	if(goal_vertex == NULL)
		return(1)
	if(is_empty())
		return(0)
}

t_graph	*graph_create(int vertex_count, char **map, int x)
{
	t_graph	*graph;
	int		i;

	graph = malloc(sizeof(t_graph));
	if (!graph)
		exit(EXIT_FAILURE);
	graph->num_vertex = vertex_count;
	graph->adj_lsts = malloc(sizeof(t_node) * vertex_count);
	if (!graph->adj_lsts)
		exit(EXIT_FAILURE);
	graph->visited = malloc(sizeof(int) * vertex_count);
	if (!graph->visited)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < vertex_count)
	{
		graph->adj_lsts[i] = NULL;
		if(map[i / x][i % x] == '1')
			graph->visited[i] = 1;
		else
			graph->visited[i] = 0;
		i ++;
	}
	return (graph);
}
void	edge_add(t_graph *graph, int src, int dest)
{
	t_node	*new_node;
	int		*content;

	content = malloc(sizeof(int));
	if (!content)
		exit(EXIT_FAILURE);
	*content = dest;
	new_node = ft_lstnew(content);
	if(!new_node)
		exit(EXIT_FAILURE);
	new_node->next = graph->adj_lsts[src];
	graph->adj_lsts[src] = new_node;
}

void	edge_add_direction(t_graph *graph, int src, t_game_board *g)
{
	char	**map;
	int		dest;

	map = g->map;
	dest = src - g->x;
	if (map[dest / g->x][dest % g->x] != '1')
		edge_add(graph, src, dest);
	dest = src + g->x;
	if (map[dest / g->x][dest % g->x] != '1')
		edge_add(graph, src, dest);
	dest = src - 1;
	if (map[dest / g->x][dest % g->x] != '1')
		edge_add(graph, src, dest);
	dest = src + 1;
	if (map[dest / g->x][dest % g->x] != '1')
		edge_add(graph, src, dest);
}

void	edge_initial(t_graph *graph, t_game_board *g)
{
	int		i;
	char 	**map;

	i = 0;
	map = g->map;
	while(i < g->x * g->y)
	{
		if(map[i / g->x][i % g->x] != '1')
			edge_add_direction(graph, i, g);
		i ++;
	}
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

void	bsq_validation(t_game_board *g)
{
	t_node	*head;
	t_graph	*graph;
	char	**map;

	map = g->map;
	head = g->goal_vertex;
	while (head != NULL)
	{
		printf("vertex is %d\n", *(int*)head->content);fflush(stdout);
		head = head -> next;
	}
	graph = graph_create(g->x * g->y, map, g->x);
	edge_initial(graph, g);
	printGraph(graph);
	bfs(graph, g->position);
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
