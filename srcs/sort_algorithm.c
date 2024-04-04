/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:21:58 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/26 16:37:18 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	current_position(t_stack **list_a, t_stack **list_b)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = *list_a;
	while (current != NULL)
	{
		current->current_position = i;
		i++;
		current = current->next;
	}
	i = 0;
	current = *list_b;
	while (current != NULL)
	{
		current->current_position = i;
		i++;
		current = current->next;
	}
}

static void	sort_half(t_stack ***list_a, t_stack ***list_b, int size, int *i)
{
	t_stack	*current;

	current = **list_a;
	while (current != NULL && (*i) - 1 > (((size - 3) / 2) + 3))
	{
		if (current->rank <= ((size - 3) / 2))
		{
			push_b(*list_a, *list_b, 0);
			(*i)--;
		}
		else
			rotate_a(*list_a, 0);
		current = **list_a;
	}
	while (current != NULL && (*i) > 3)
	{
		if (current->rank <= size - 3)
		{
			push_b(*list_a, *list_b, 0);
			(*i)--;
		}
		else
			rotate_a(*list_a, 0);
		current = **list_a;
	}
}

static void	build_stack_b(t_stack ***list_a, t_stack ***list_b)
{
	int		size;
	int		i;

	size = stack_size(*list_a);
	i = size;
	while (i > 3)
		sort_half(list_a, list_b, size, &i);
}

void	sort_algorithm(t_stack ***list_a, t_stack ***list_b)
{
	int		full_size;

	full_size = stack_size(*list_a);
	final_rank(*list_a);
	build_stack_b(list_a, list_b);
	sort_three(list_a);
	current_position(*list_a, *list_b);
	build_costs(list_a, list_b);
	while ((full_size > stack_size(*list_a)))
	{
		find_cheapest(list_a, list_b);
		current_position(*list_a, *list_b);
		build_costs(list_a, list_b);
	}
	return ;
}
