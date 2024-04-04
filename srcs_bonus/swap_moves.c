/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:52:35 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/26 16:25:26 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_stack **a, int i)
{
	t_stack	*old_top;
	t_stack	*new_top;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	old_top = *a;
	new_top = (*a)->next;
	old_top->next = new_top->next;
	if (new_top->next != NULL)
		new_top->next->prev = old_top;
	old_top->prev = new_top;
	new_top->prev = NULL;
	new_top->next = old_top;
	*a = new_top;
	if (i != 1)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack **b, int i)
{
	t_stack	*old_top;
	t_stack	*new_top;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	old_top = *b;
	new_top = (*b)->next;
	old_top->next = new_top->next;
	if (new_top->next != NULL)
		new_top->next->prev = old_top;
	old_top->prev = new_top;
	new_top->prev = NULL;
	new_top->next = old_top;
	*b = new_top;
	if (i != 1)
		ft_putstr_fd("sb\n", 1);
}

void	swap_ss(t_stack **a, t_stack **b, int i)
{
	swap_a(a, 1);
	swap_b(b, 1);
	if (i != 1)
		ft_putstr_fd("ss\n", 1);
}
