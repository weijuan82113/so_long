/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 00:47:47 by wchen             #+#    #+#             */
/*   Updated: 2022/12/25 17:08:46 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if (map[i / x][i % x] == '1')
			graph->visited[i] = 1;
		else
			graph->visited[i] = 0;
		i++;
	}
	return (graph);
}
