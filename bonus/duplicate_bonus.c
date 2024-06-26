/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:02:45 by alafdili          #+#    #+#             */
/*   Updated: 2024/04/19 12:58:49 by alafdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	search(int data, t_stack *to_search)
{
	while (to_search)
	{
		if (to_search->data == data)
			return (1);
		else
			to_search = to_search->next;
	}
	return (0);
}

void	check_duplicat(t_stack **list)
{
	t_stack	*temp;

	temp = *list;
	while (temp)
	{
		if (search(temp->data, temp->next) == 1)
		{
			list_clear(*list, NULL, 0);
			write(2, "Error\n", 7);
			exit(1);
		}
		else
			temp = temp -> next;
	}
}
