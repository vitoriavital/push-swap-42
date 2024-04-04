/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:13:44 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/18 19:11:33 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*lstnew(int number, char type)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->number = number;
	node->type = type;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

int	lstsize(t_stack *lst)
{
	t_stack	*current;
	int		size;

	size = 0;
	current = lst;
	while (current->next != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (new != NULL)
	{
		current = *lst;
		if (current != NULL)
		{
			new->next = current;
			current->prev = new;
		}
		*lst = new;
	}
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (*lst == NULL && new != NULL)
	{
		*lst = new;
		return ;
	}
	if (new != NULL)
	{
		current = *lst;
		if (current != NULL)
		{
			while (current->next != NULL)
				current = current->next;
			current->next = new;
			new->prev = current;
		}
		else
			*lst = new;
	}
}

void	lstclear(t_stack **lst)
{
	t_stack	*current;
	t_stack	*next;

	if (*lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free (current);
		current = next;
	}
	*lst = NULL;
}
