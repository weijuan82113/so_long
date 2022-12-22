/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:12:43 by wchen             #+#    #+#             */
/*   Updated: 2022/12/23 04:31:54 by wchen            ###   ########.fr       */
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
	if (direct == ASC)
		ft_lst_ascsort(&adj_lst);
	else
		ft_lst_descsort(&adj_lst);
	move_p = *(int *)adj_lst->content;
	while (g->map[move_p / g->x][move_p % g->x] != '0' && adj_lst != NULL)
	{
		move_p = *(int *)adj_lst->content;
		adj_lst = adj_lst->next;
	}
	if (adj_lst == NULL)
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
