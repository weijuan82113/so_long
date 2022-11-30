/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:09:11 by wchen             #+#    #+#             */
/*   Updated: 2022/11/30 23:46:08 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putx_fd(unsigned int un_int, int fd)
{
	char	num;

	if (un_int > 15)
	{
		ft_putx_fd(un_int / 16, fd);
		ft_putx_fd(un_int % 16, fd);
	}
	else
	{
		if (un_int > 9)
			num = un_int - 10 + 'a';
		else
			num = un_int + '0';
		ft_putchar_fd(num, fd);
	}
}

int	print_x(unsigned int un_int)
{
	int				count_digit;
	unsigned int	temp_int;

	count_digit = 0;
	temp_int = un_int;
	if (un_int == 0)
		count_digit++;
	while (temp_int != 0)
	{
		count_digit++;
		temp_int /= 16;
	}
	ft_putx_fd(un_int, 1);
	return (count_digit);
}
