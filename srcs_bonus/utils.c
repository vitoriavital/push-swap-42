/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:10:24 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/18 19:17:39 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_size(t_stack **stack)
{
	t_stack	*current;
	int		size;

	current = *stack;
	size = 0;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	free_split(char ***split, int n)
{
	int	i;

	i = 0;
	while ((*split)[i] != NULL)
	{
		free ((*split)[i]);
		i++;
	}
	free ((*split));
	return (n);
}
