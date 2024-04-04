/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:38:22 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/26 16:36:54 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	move_both_stacks(int *move_a, int *move_b,
		t_stack ***list_a, t_stack ***list_b)
{
	while ((*move_a) < 0 && (*move_b) < 0)
	{
		reverse_rrr(*list_a, *list_b, 0);
		(*move_a)++;
		(*move_b)++;
	}
	while ((*move_a) > 0 && (*move_b) > 0)
	{
		rotate_rr(*list_a, *list_b, 0);
		(*move_a)--;
		(*move_b)--;
	}
	while ((*move_b) != 0)
	{
		if ((*move_b) < 0)
		{
			reverse_rb(*list_b, 0);
			(*move_b)++;
		}
		else
		{
			rotate_b(*list_b, 0);
			(*move_b)--;
		}
	}
}

static void	move_cheapest(int move_a, int move_b,
		t_stack ***list_a, t_stack ***list_b)
{
	if (move_a == 0 && move_b == 0)
	{
		push_a(*list_a, *list_b, 0);
		return ;
	}
	move_both_stacks(&move_a, &move_b, list_a, list_b);
	while (move_a != 0)
	{
		if (move_a < 0)
		{
			reverse_ra(*list_a, 0);
			move_a++;
		}
		else
		{
			rotate_a(*list_a, 0);
			move_a--;
		}
	}
	push_a(*list_a, *list_b, 0);
	return ;
}

void	find_cheapest(t_stack ***list_a, t_stack ***list_b)
{
	t_stack	*current;
	t_stack	*cheapest;

	current = **list_b;
	cheapest = **list_b;
	while (current != NULL)
	{
		current->full_cost = 0;
		if (current->cost_top_a < 0)
			current->full_cost += current->cost_top_a * -1;
		else
			current->full_cost += current->cost_top_a;
		if (current->cost_top_b < 0)
			current->full_cost += current->cost_top_b * -1;
		else
			current->full_cost += current->cost_top_b;
		if (cheapest->full_cost > current->full_cost)
			cheapest = current;
		current = current->next;
	}
	move_cheapest(cheapest->cost_top_a, cheapest->cost_top_b, list_a, list_b);
}
