/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:37:11 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/26 16:34:56 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_stack **a, t_stack **b, int i)
{
	t_stack	*old_top_a;
	t_stack	*old_top_b;
	t_stack	*new_top_a;
	t_stack	*new_top_b;

	if (*b == NULL)
		return ;
	old_top_a = *a;
	old_top_b = *b;
	new_top_a = old_top_b;
	new_top_b = (*b)->next;
	if (new_top_b != NULL)
		new_top_b->prev = NULL;
	new_top_a->prev = NULL;
	new_top_a->next = old_top_a;
	if (old_top_a != NULL)
		old_top_a->prev = new_top_a;
	if (new_top_a != NULL)
		new_top_a->type = 'a';
	if (new_top_b != NULL)
		new_top_b->type = 'b';
	*a = new_top_a;
	*b = new_top_b;
	if (i != 1)
		ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack **a, t_stack **b, int i)
{
	t_stack	*old_top_a;
	t_stack	*old_top_b;
	t_stack	*new_top_a;
	t_stack	*new_top_b;

	if (*a == NULL)
		return ;
	old_top_a = *a;
	old_top_b = *b;
	new_top_b = old_top_a;
	new_top_a = (*a)->next;
	if (new_top_a != NULL)
		new_top_a->prev = NULL;
	new_top_b->prev = NULL;
	new_top_b->next = old_top_b;
	if (old_top_b != NULL)
		old_top_b->prev = new_top_b;
	if (new_top_a != NULL)
		new_top_a->type = 'a';
	if (new_top_b != NULL)
		new_top_b->type = 'b';
	*a = new_top_a;
	*b = new_top_b;
	if (i != 1)
		ft_putstr_fd("pb\n", 1);
}
