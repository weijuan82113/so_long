/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:24:37 by wchen             #+#    #+#             */
/*   Updated: 2022/11/30 19:20:11 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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
		if(line == NULL)
			break;
	}

}
