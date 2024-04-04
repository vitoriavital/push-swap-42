/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:28:26 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/22 15:35:38 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*max_node(t_stack **list)
{
	t_stack	*max;
	t_stack	*current;

	if (*list == NULL)
		return (NULL);
	max = *list;
	current = (*list)->next;
	while (current != NULL)
	{
		if (max->number < current->number)
			max = current;
		current = current->next;
	}
	return (max);
}

t_stack	*min_node(t_stack **list)
{
	t_stack	*min;
	t_stack	*current;

	if (*list == NULL)
		return (NULL);
	min = *list;
	current = (*list)->next;
	while (current != NULL)
	{
		if (min->number > current->number)
			min = current;
		current = current->next;
	}
	return (min);
}

void	sort_three(t_stack ***list)
{
	t_stack	*min;
	t_stack	*max;

	if (is_sorted(*list))
		return ;
	max = max_node(*list);
	min = min_node(*list);
	if ((**list) == max && (**list)->next == min)
		rotate_a(*list, 0);
	else if ((**list) == max && (**list)->next != min)
		swap_a(*list, 0);
	else if ((**list) == min)
		reverse_ra(*list, 0);
	else if ((**list)->next == min)
		swap_a(*list, 0);
	else
		reverse_ra(*list, 0);
	sort_three(list);
	return ;
}
