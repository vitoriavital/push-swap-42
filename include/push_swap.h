/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:15:12 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/26 16:35:43 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/include/get_next_line.h"
# include "../lib/libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	char			type;
	struct s_stack	*prev;
	struct s_stack	*next;
	int				number;
	int				rank;
	int				current_position;
	int				cost_top_b;
	int				cost_top_a;
	int				full_cost;
}					t_stack;

typedef struct s_target_a
{
	int	rank;
	int	current_position;
}					t_target_a;

t_stack				*lstnew(int number, char type);
int					lstsize(t_stack *lst);
void				lstadd_front(t_stack **lst, t_stack *new);
void				lstadd_back(t_stack **lst, t_stack *new);
void				lstclear(t_stack **lst);
void				swap_a(t_stack **a, int i);
void				swap_b(t_stack **b, int i);
void				swap_ss(t_stack **a, t_stack **b, int i);
void				push_a(t_stack **a, t_stack **b, int i);
void				push_b(t_stack **a, t_stack **b, int i);
void				rotate_a(t_stack **a, int i);
void				rotate_b(t_stack **b, int i);
void				rotate_rr(t_stack **a, t_stack **b, int i);
void				reverse_ra(t_stack **a, int i);
void				reverse_rb(t_stack **b, int i);
void				reverse_rrr(t_stack **a, t_stack **b, int i);
int					free_split(char ***split, int n);
int					stack_size(t_stack **stack);
int					is_digit(char *str);
int					check_duplicates(char *seen, char *str);
int					is_sorted(t_stack **list);
t_stack				*min_node(t_stack **list);
t_stack				*max_node(t_stack **list);
void				sort_three(t_stack ***list_a);
void				sort_algorithm(t_stack ***list_a, t_stack ***list_b);
int					validate_input(int argc, char **argv, t_stack ***list);
void				find_cheapest(t_stack ***list_a, t_stack ***list_b);
void				final_rank(t_stack **list_a);
t_stack				*build_costs(t_stack ***list_a, t_stack ***list_b);

#endif
