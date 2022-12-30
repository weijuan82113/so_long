/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:24:37 by wchen             #+#    #+#             */
/*   Updated: 2022/12/30 15:40:18 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	line_valid(char *line, t_game_board *g_board, int y)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (object_validation(line[i], g_board))
			ft_error(OBJ_ERR);
		i++;
	}
	if (y == 0)
		g_board->x = i;
	else if (i != g_board->x)
		ft_error(RECTANGLE_ERR);
	if (!g_board->map_head)
		g_board->map_head = ft_lstnew(line);
	else
		ft_lstadd_back(&(g_board->map_head), ft_lstnew(line));
}

static void	map_arr_create(t_game_board *g)
{
	t_node	*head;
	int		i;

	head = g->map_head;
	i = 0;
	g->map = malloc(sizeof(char *) * (g->y + 1));
	if (!g->map)
		exit(EXIT_FAILURE);
	while (head)
	{
		if (i % g->x == 0)
		{
			g->map[i / g->x] = ft_calloc(g->x + 1, sizeof(char));
			if (!g->map[i / g->x])
				exit(EXIT_FAILURE);
		}
		wall_validation(g, ((char *)head->content)[i % g->x], i);
		g->map[i / g->x][i % g->x] = ((char *)head->content)[i % g->x];
		bfs_obj_initial(g, g->map[i / g->x][i % g->x], i);
		if (i % g->x == g->x - 1)
			head = head->next;
		i++;
	}
	g->map[g->y] = NULL;
}

static t_game_board	*game_board_inital(void)
{
	t_game_board	*g_board;

	g_board = malloc(sizeof(t_game_board));
	if (!g_board)
		exit(EXIT_FAILURE);
	g_board->collect_count = 0;
	g_board->exit_count = 0;
	g_board->player_count = 0;
	g_board->empty_count = 0;
	g_board->wall_count = 0;
	g_board->x = 0;
	g_board->y = 0;
	g_board->size = 0;
	g_board->position = 0;
	g_board->goal_position = 0;
	g_board->step = 0;
	g_board->map_head = NULL;
	g_board->judge_obj = NULL;
	g_board->graph = NULL;
	g_board->attack = 0;
	g_board->die = 0;
	g_board->e_attack = 0;
	g_board->e_position = 0;
	g_board->frame = 0;
	return (g_board);
}

static void	file_name_validation(char *file_name)
{
	char	*ext;
	char	*ber;

	ber = ".ber";
	ext = ft_strrchr(file_name, '.');
	if (ext == NULL)
		ft_error(FILE_EXT_ERR);
	while (*ext != '\0' && *ber != '\0')
	{
		if (*(ext) != *ber)
			ft_error(FILE_EXT_ERR);
		ext++;
		ber++;
	}
	if (*ext != '\0' || *ber != '\0')
		ft_error(FILE_EXT_ERR);
}

t_game_board	*map_initial(int argc, char **argv)
{
	int				fd;
	char			*line;
	t_game_board	*g_board;

	if (argc != 2)
		ft_error(ARG_ERR);
	file_name_validation(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(FILE_ERR);
	line = NULL;
	g_board = game_board_inital();
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line_valid(line, g_board, g_board->y);
		g_board->y++;
	}
	map_validation(g_board);
	map_arr_create(g_board);
	bfs_validation(g_board);
	return (g_board);
}
