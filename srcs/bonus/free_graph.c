/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:46:53 by wchen             #+#    #+#             */
/*   Updated: 2022/12/30 00:50:37 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_graph(t_graph *graph)
{
	int	i;

	i = 0;
	while (i < graph->num_vertex)
	{
		ft_lstclear(&(graph->adj_lsts[i]), free);
		i++;
	}
	free(graph->adj_lsts);
	free(graph->visited);
	free(graph);
}
