/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:24:37 by wchen             #+#    #+#             */
/*   Updated: 2022/11/24 21:59:16 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q so_long");
}

int	main(int argc, char ** argv)
{
	int		fd;
	char	*line;

	if(argc != 2)
		ft_printf("worng argument");
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		printf("line is %s", line);
		free (line);
		if(line == NULL)
			break;
	}

}
