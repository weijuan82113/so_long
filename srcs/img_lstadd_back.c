/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:52:44 by wchen             #+#    #+#             */
/*   Updated: 2022/12/08 23:22:39 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	img_lstadd_back(t_img **head, t_img *new)
{
	t_img	*tail;

	if (!head || !new)
		return ;
	else if (!*head)
		*head = new;
	else
	{
		tail = *head;
		while (tail -> next != NULL)
			tail =  tail -> next;
		tail -> next = new;
	}
}
