/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:41:01 by mavitori          #+#    #+#             */
/*   Updated: 2024/04/03 19:09:15 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	build_seen_values(char *og_str, char **seen_values)
{
	char	*str;
	char	*new_str;
	int		duplicates;
	char	*temp;

	str = ft_strjoin(og_str, " ");
	new_str = ft_strjoin(" ", str);
	free(str);
	duplicates = check_duplicates(*seen_values, new_str);
	if (duplicates == 0)
	{
		temp = ft_strjoin(*seen_values, new_str);
		free(new_str);
		if (temp == NULL)
			return (-1);
		free(*seen_values);
		*seen_values = temp;
	}
	else
	{
		free(new_str);
		return (-1);
	}
	return (0);
}

static int	build_list(char *str, t_stack ***list, char **seen_values)
{
	long	num;
	t_stack	*node;
	char	*number;
	int		i;

	i = 0;
	if (is_digit(str) == 0)
		num = ft_atoi((const char *)str);
	else
		return (-1);
	if (num > 2147483647 || num < -2147483648)
		return (-1);
	number = ft_itoa(num);
	if (build_seen_values(number, seen_values) == -1)
	{
		free (number);
		return (-1);
	}
	node = lstnew(num, 'a');
	lstadd_back(*list, node);
	free(number);
	return (0);
}

static int	check_input(char ***split, char **seen_values, t_stack ***list)
{
	char	*value;
	int		j;

	j = 0;
	value = (*split)[j];
	if (value == NULL)
	{
		free(*seen_values);
		return (free_split(&(*split), -1));
	}
	while (value != NULL)
	{
		if (build_list(value, list, &(*seen_values)) == -1)
		{
			free(*seen_values);
			return (free_split(&(*split), -1));
		}
		j++;
		value = (*split)[j];
	}
	return (0);
}

static int	initialize_seen_values(char **seen_values)
{
	if (*seen_values == NULL)
	{
		*seen_values = malloc(sizeof(char));
		if (*seen_values == NULL)
			return (-1);
		(*seen_values)[0] = '\0';
	}
	return (0);
}

int	validate_input(int argc, char **argv, t_stack ***list)
{
	int			i;
	char		*arg;
	char		**split;
	static char	*seen_values;

	i = 1;
	if (initialize_seen_values(&seen_values) == -1)
		return (-1);
	while (i < argc)
	{
		arg = argv[i];
		split = ft_split(arg, ' ');
		if (check_input(&split, &seen_values, list) == -1)
			return (-1);
		free_split(&split, 0);
		i++;
	}
	free(seen_values);
	return (0);
}
