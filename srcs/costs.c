/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:02:50 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/18 19:43:52 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	build_cost_stack_a(t_target_a **target, int size,
		t_stack ***list_a, t_stack *current_a)
{
	int	cost_a;

	cost_a = 0;
	if ((*target)->rank != 2147483647)
	{
		current_a = **list_a;
		while (current_a != NULL && (*target)->rank == 2147483647)
		{
			if (current_a->rank < (*target)->rank)
			{
				(*target)->rank = current_a->rank;
				(*target)->current_position = current_a->current_position;
			}
			current_a = current_a->next;
		}
	}
	if ((*target)->current_position > size / 2)
		cost_a = (size - (*target)->current_position) * -1;
	else
		cost_a = (*target)->current_position;
	return (cost_a);
}

static int	build_cost_a(t_stack ***list_a, t_stack *node_b)
{
	int			cost_a;
	int			size;
	t_stack		*current_a;
	t_target_a	*target;

	cost_a = 0;
	size = stack_size(*list_a);
	current_a = **list_a;
	target = malloc(sizeof(t_target_a));
	target->current_position = 0;
	target->rank = 2147483647;
	while (current_a != NULL)
	{
		if (current_a->rank > node_b->rank && current_a->rank < target->rank)
		{
			target->rank = current_a->rank;
			target->current_position = current_a->current_position;
		}
		current_a = current_a->next;
	}
	cost_a = build_cost_stack_a(&target, size, list_a, current_a);
	free(target);
	return (cost_a);
}

static int	build_cost_b(t_stack ***list_b, t_stack *node_b)
{
	int	cost_b;
	int	size;

	cost_b = 0;
	size = stack_size(*list_b);
	if (node_b->current_position > size / 2)
		cost_b = (size - node_b->current_position) * -1;
	else
		cost_b = node_b->current_position;
	return (cost_b);
}

t_stack	*build_costs(t_stack ***list_a, t_stack ***list_b)
{
	t_stack	*current_b;
	t_stack	*min;

	current_b = **list_b;
	min = NULL;
	while (current_b != NULL)
	{
		current_b->cost_top_b = build_cost_b(list_b, current_b);
		current_b->cost_top_a = build_cost_a(list_a, current_b);
		current_b = current_b->next;
	}
	return (min);
}
