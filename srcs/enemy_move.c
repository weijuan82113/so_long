/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:12:43 by wchen             #+#    #+#             */
/*   Updated: 2022/12/29 23:17:03 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	position_judge(int enemy, int player)
{
	if (enemy < player)
		return (ASC);
	else
		return (DESC);
}

void print_lst(t_graph *graph)
{
	int i;
	int	count;
	t_node	*node;

	count = graph->num_vertex;
	i = 0;
	while (i < count)
	{
		node = graph->adj_lsts[i];
		printf("%d :",i);
		while(node)
		{
			printf("%d->", *(int *)node->content);
			node = node->next;
		}
		printf("\n");
		i ++;
	}
}

static void	move_to(int direct, t_game_board *g, t_node *enemy)
{
	t_node	*adj_lst;
	int		p;
	int		move_p;

	(void) direct;
	p = *(int *)enemy->content;
	if (p == 0)
		return ;
	adj_lst = g->graph->adj_lsts[p];
	printf("adj_lst ptr %p\n", &adj_lst);
	printf("g->graph->adj_lsts[p] ptr %p\n", &g->graph->adj_lsts[p]);
	printf("-----printlst1-----\n");
	print_lst(g->graph);
	printf("-----finished1-----\n");
	if (direct == ASC)
		ft_lst_ascsort(&g->graph->adj_lsts[p]);
	else
		ft_lst_descsort(&g->graph->adj_lsts[p]);
	printf("-----printlst2-----\n");
	print_lst(g->graph);
	printf("-----finished2-----\n");
	move_p = *(int *)adj_lst->content;
	printf("p :%d", p);
	printf("move to %d\n",move_p);
	while (g->map[move_p / g->x][move_p % g->x] != '0' && adj_lst->next != NULL)
	{
		adj_lst = adj_lst->next;
		move_p = *(int *)adj_lst->content;
	}
	if (adj_lst->next == NULL && g->map[move_p / g->x][move_p % g->x] != '0')
		return ;
	g->map[move_p / g->x][move_p % g->x] = 'C';
	g->map[p / g->x][p % g->x] = '0';
	*(int *)enemy->content = move_p;
}

void	enemy_move(t_mlx *t_mlx)
{
	t_node	*enemy;
	int		direct;

	enemy = t_mlx->g->judge_obj;
	while (enemy != NULL)
	{
		direct = position_judge(*(int *)enemy->content, t_mlx->g->position);
		if (direct == ASC)
			move_to(ASC, t_mlx->g, enemy);
		else
			move_to(DESC, t_mlx->g, enemy);
		enemy = enemy->next;
	}
	usleep(400000);
}
