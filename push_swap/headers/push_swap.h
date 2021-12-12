/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:46:32 by hardella          #+#    #+#             */
/*   Updated: 2021/12/12 20:35:01 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>  //need to delete

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}				t_stack;

void		display(t_stack *stack_a);
void		sort_three(t_stack **stack_a);
void		sort_five(t_stack **stack_a, t_stack **stack_b);
void		help_sort(int n1, int n2, t_stack **stack_a, t_stack **stack_b);

long int	atoi_ps(char *str);
int			not_in(t_stack *stack_a, int value);
int			check_sort(t_stack *stack_a);
void		get_stack(t_stack **stack_a, char **argv, int argc);

t_stack		*create(t_stack **stack_a, int value);
void		push_back(t_stack **stack_a, int value);
void		push_front(t_stack **stack_a, int value);

void		exit_list(t_stack **stack_a);
void		error_input(t_stack **stack_a);
void		error_input_empty(t_stack **stack_a);
void		free_stack(t_stack **stack_a);

int			ft_strlen(const char *s);
int			min_max(long int a);
int			ft_isint(char *str);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);

void		sa(t_stack **stack_a, int f);
void		sb(t_stack	**stack_b, int f);
void		ss(t_stack **stack_a, t_stack **stack_b, int f);
void		ra(t_stack **stack_a, int f);
void		rb(t_stack	**stack_b, int f);
void		rr(t_stack **stack_a, t_stack **stack_b, int f);
void		rra(t_stack **stack_a, int f);
void		rrb(t_stack **stack_b, int f);
void		rrr(t_stack **stack_a, t_stack **stack_b, int f);
void		pa(t_stack **stack_a, t_stack **stack_b, int f);
void		pb(t_stack **stack_a, t_stack **stack_b, int f);

#endif