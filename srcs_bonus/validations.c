/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:42:42 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/26 16:53:44 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_digit(char *str)
{
	int	i;
	int	check;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	check = i;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	if (check == i)
		return (-1);
	return (0);
}

int	check_duplicates(char *seen, char *str)
{
	int		size;
	char	*result;

	size = ft_strlen(seen);
	if (seen == NULL)
		return (0);
	result = ft_strnstr(seen, str, size);
	if (result != 0)
		return (-1);
	else
		return (0);
}

int	is_sorted(t_stack **list)
{
	t_stack	*current;

	if (*list == NULL)
		return (-1);
	current = *list;
	while (current != NULL)
	{
		if (current->next != NULL)
		{
			if (current->number > current->next->number)
			{
				return (0);
			}
		}
		current = current->next;
	}
	return (1);
}
