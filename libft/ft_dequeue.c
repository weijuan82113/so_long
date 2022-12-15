/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequeue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:48:32 by wchen             #+#    #+#             */
/*   Updated: 2022/12/15 23:11:26 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dequeue(t_queue *q)
{
	t_node	*temp;

	if (q->front == NULL)
		return;
	temp = q->front;
	q->front = q->front->next;
	if(q->front == NULL)
		q->rear = NULL;
	ft_lstdelone(temp, free);
}
