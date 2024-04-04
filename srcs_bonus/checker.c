/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:54:05 by mavitori          #+#    #+#             */
/*   Updated: 2024/04/03 22:59:37 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	execute_cmd(char **cmd, t_stack ***list_a, t_stack ***list_b,
		int *invalid)
{
	if (ft_strncmp("ra\n", *cmd, 4) == 0)
		rotate_a(*list_a, 1);
	else if (ft_strncmp("rb\n", *cmd, 4) == 0)
		rotate_b(*list_b, 1);
	else if (ft_strncmp("rr\n", *cmd, 4) == 0)
		rotate_rr(*list_a, *list_b, 1);
	else if (ft_strncmp("sa\n", *cmd, 4) == 0)
		swap_a(*list_a, 1);
	else if (ft_strncmp("sb\n", *cmd, 4) == 0)
		swap_b(*list_b, 1);
	else if (ft_strncmp("ss\n", *cmd, 4) == 0)
		swap_ss(*list_a, *list_b, 1);
	else if (ft_strncmp("rra\n", *cmd, 5) == 0)
		reverse_ra(*list_a, 1);
	else if (ft_strncmp("rrb\n", *cmd, 5) == 0)
		reverse_rb(*list_b, 1);
	else if (ft_strncmp("rrr\n", *cmd, 5) == 0)
		reverse_rrr(*list_a, *list_b, 1);
	else if (ft_strncmp("pa\n", *cmd, 4) == 0)
		push_a(*list_a, *list_b, 1);
	else if (ft_strncmp("pb\n", *cmd, 4) == 0)
		push_b(*list_a, *list_b, 1);
	else
		*invalid = 1;
}

static void	read_cmds(t_stack ***list_a, t_stack ***list_b)
{
	char	*line;
	int		invalid;

	invalid = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		execute_cmd(&line, list_a, list_b, &invalid);
		free(line);
		line = NULL;
		if (invalid == 1)
			break ;
	}
	if (invalid == 1)
		ft_putstr_fd("Error\n", 2);
	else if (is_sorted(*list_a) == 1 && **list_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
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
	read_cmds(&list_a, &list_b);
	lstclear(list_a);
	lstclear(list_b);
	free(list_a);
	free(list_b);
	return (0);
}
