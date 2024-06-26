/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:14:15 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/19 12:58:49 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sb(t_stack **head_b)
{
	t_stack	*temp;

	temp = *head_b;
	if (*head_b && (*head_b)->next)
	{
		*head_b = (*head_b)->next;
		temp->next = (*head_b)->next;
		(*head_b)->next = temp;
	}
}
