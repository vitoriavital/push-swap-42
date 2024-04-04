/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:15:12 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/26 16:35:32 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
int					is_sorted(t_stack **list);
int					validate_input(int argc, char **argv, t_stack ***list);

#endif
