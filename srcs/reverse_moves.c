/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:28:00 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/26 16:26:56 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_ra(t_stack **a, int i)
{
	t_stack	*old_top;
	t_stack	*new_top;
	t_stack	*bottom;
	t_stack	*new_bottom;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	old_top = *a;
	bottom = old_top;
	while (bottom->next != NULL)
		bottom = bottom->next;
	new_top = bottom;
	new_bottom = bottom->prev;
	new_bottom->next = NULL;
	old_top->prev = new_top;
	new_top->prev = NULL;
	new_top->next = old_top;
	*a = new_top;
	if (i != 1)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_rb(t_stack **b, int i)
{
	t_stack	*old_top;
	t_stack	*new_top;
	t_stack	*bottom;
	t_stack	*new_bottom;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	old_top = *b;
	bottom = old_top;
	while (bottom->next != NULL)
		bottom = bottom->next;
	new_top = bottom;
	new_bottom = bottom->prev;
	new_bottom->next = NULL;
	old_top->prev = new_top;
	new_top->prev = NULL;
	new_top->next = old_top;
	*b = new_top;
	if (i != 1)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_rrr(t_stack **a, t_stack **b, int i)
{
	reverse_ra(a, 1);
	reverse_rb(b, 1);
	if (i != 1)
		ft_putstr_fd("rrr\n", 1);
}
