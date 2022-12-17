/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_initial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 00:48:56 by wchen             #+#    #+#             */
/*   Updated: 2022/12/17 14:00:47 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	edge_add(t_graph *graph, int src, int dest)
{
	t_node	*new_node;
	int		*content;

	content = malloc(sizeof(int));
	if (!content)
		exit(EXIT_FAILURE);
	*content = dest;
	new_node = ft_lstnew(content);
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->next = graph->adj_lsts[src];
	graph->adj_lsts[src] = new_node;
}

static void	edge_add_direction(t_graph *graph, int src, t_game_board *g)
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
	char	**map;

	i = 0;
	map = g->map;
	while (i < g->x * g->y)
	{
		if (map[i / g->x][i % g->x] != '1')
			edge_add_direction(graph, i, g);
		i++;
	}
}
