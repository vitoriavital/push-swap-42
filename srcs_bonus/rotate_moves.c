/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:51:28 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/26 16:25:42 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_stack **a, int i)
{
	t_stack	*old_top;
	t_stack	*new_top;
	t_stack	*bottom;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	old_top = *a;
	new_top = old_top->next;
	bottom = old_top;
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->next = old_top;
	old_top->prev = bottom;
	old_top->next = NULL;
	new_top->prev = NULL;
	*a = new_top;
	if (i != 1)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack **b, int i)
{
	t_stack	*old_top;
	t_stack	*new_top;
	t_stack	*bottom;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	old_top = *b;
	new_top = old_top->next;
	bottom = old_top;
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->next = old_top;
	old_top->prev = bottom;
	old_top->next = NULL;
	new_top->prev = NULL;
	*b = new_top;
	if (i != 1)
		ft_putstr_fd("rb\n", 1);
}

void	rotate_rr(t_stack **a, t_stack **b, int i)
{
	rotate_a(a, 1);
	rotate_b(b, 1);
	if (i != 1)
		ft_putstr_fd("rr\n", 1);
}
