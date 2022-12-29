/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:57:21 by wchen             #+#    #+#             */
/*   Updated: 2022/12/28 19:41:04 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_mlx *t_mlx, char *exit_msg)
{
	ft_printf(exit_msg);
	free_all(t_mlx);
	exit(EXIT_SUCCESS);
}
