// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_inital.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:24:37 by wchen             #+#    #+#             */
/*   Updated: 2022/12/06 22:10:22 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void line_valid(char *line, t_game_board *g_board, int y)
{
	int 	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if(object_validation(line[i], g_board))
			ft_error(OBJ_ERR);
		i ++;
	}
	if (y == 0)
		g_board -> x = i;
	else if (i != g_board -> x)
		ft_error(RECTANGLE_ERR);
	if (! g_board -> map_head)
		g_board -> map_head = ft_lstnew(line);
	else
		ft_lstadd_back(&(g_board -> map_head), ft_lstnew(line));
}

static void map_arr_create(t_game_board *g)
{
	t_node		*head;
	int			i;

	head = g -> map_head;
	i = 0;
	g -> map = malloc(sizeof(char *) * g -> y);
	if (!g -> map)
		exit(EXIT_FAILURE);
	while (head)
	{
		if (i % g -> x == 0)
		{
			g -> map[i / g -> x] = ft_calloc(g -> x + 1,sizeof(char));
			if (!g -> map[i / g -> x])
				exit(EXIT_FAILURE);
		}
		wall_validation(g, ((char *)head -> content)[i % g -> x], i);
		g -> map[i / g -> x][i % g -> x] = ((char *)head -> content)[i % g -> x];
		if (((char *)head -> content)[i % g -> x] == 'P')
			g -> position = i;
		if (i % g -> x == g -> x -1)
			head = head -> next;
		i ++;
	}
}

static t_game_board	*game_board_inital(void)
{
	t_game_board	*g_board;

	g_board = malloc(sizeof(t_game_board));
	if (!g_board)
		exit (EXIT_FAILURE);
	g_board -> collect_count = 0;
	g_board -> exit_count = 0;
	g_board -> player_count = 0;
	g_board -> empty_count = 0;
	g_board -> wall_count = 0;
	g_board -> x = 0;
	g_board -> y = 0;
	g_board -> size = 0;
	g_board -> position = 0;
	g_board -> map_head = NULL;
	return (g_board);
}

static void file_name_validation(char *file_name)
{
	char	*ext;
	char	*ber;

	ber = ".ber";
	ext = ft_strrchr(file_name,'.');
	if(ext == NULL)
		ft_error(FILE_EXT_ERR);
	while (*ext != '\0' && *ber != '\0')
	{
		if(*(ext) != *ber)
			ft_error(FILE_EXT_ERR);
		ext ++;
		ber ++;
	}
	if (*ext != '\0' || *ber != '\0')
		ft_error(FILE_EXT_ERR);
}

t_game_board	*map_initial(int argc, char **argv)
{
	int				fd;
	char			*line;
	int				i;
	t_game_board	*g_board;

	if (argc != 2)
		ft_error(ARG_ERR);
	file_name_validation(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(FILE_ERR);
	line = NULL;
	g_board = game_board_inital();
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		line_valid(line, g_board, i);
		i ++;
	}
	g_board -> y = i;
	map_validation(g_board);
	map_arr_create(g_board);
	return (g_board);
}
