/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:28:06 by mavitori          #+#    #+#             */
/*   Updated: 2024/04/01 15:55:39 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	final_sort(t_stack **list_a)
{
	if (min_node(list_a)->rank >= stack_size(list_a) / 2)
	{
		while (min_node(list_a)->prev != NULL)
			rotate_a(list_a, 0);
	}
	else
	{
		while (min_node(list_a)->prev != NULL)
			reverse_ra(list_a, 0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	**list_a;
	t_stack	**list_b;

	if (argc == 1)
		return (-1);
	list_a = (t_stack **)malloc(sizeof(t_stack *));
	*list_a = NULL;
	if (validate_input(argc, argv, &list_a) != 0)
	{
		ft_putstr_fd("Error\n", 2);
		lstclear(list_a);
		free(list_a);
		return (-1);
	}
	list_b = (t_stack **)malloc(sizeof(t_stack *));
	*list_b = NULL;
	if (is_sorted(list_a) != 1)
		sort_algorithm(&list_a, &list_b);
	if (is_sorted(list_a) != 1)
		final_sort(list_a);
	lstclear(list_a);
	lstclear(list_b);
	free(list_a);
	free(list_b);
	return (0);
}
