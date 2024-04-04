/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:36:36 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/22 16:01:24 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	max_number(t_stack **list, int max_n, int i)
{
	t_stack	*current;
	int		max;

	if (*list == NULL)
		return (0);
	current = (*list);
	max = (*list)->number;
	if (max_n == 2147483647 && max == max_n && i == 0)
		max = max_n;
	else if (max >= max_n)
		max = -2147483648;
	while (current != NULL)
	{
		if (max <= current->number && current->number < max_n)
			max = current->number;
		else if (current->number == max_n && max_n == 2147483647 && i == 0)
			max = max_n;
		current = current->next;
	}
	return (max);
}

void	final_rank(t_stack **list_a)
{
	t_stack	*current;
	int		size;
	int		max;

	max = max_number(list_a, 2147483647, 0);
	size = stack_size(list_a);
	current = *list_a;
	while (current != NULL && size > 0)
	{
		if (current->number == max)
		{
			max = current->number;
			max = max_number(list_a, max, 1);
			current->rank = size;
			size--;
		}
		current = current->next;
		if (current == NULL && size > 0)
			current = *list_a;
	}
}
