/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:46:32 by hardella          #+#    #+#             */
/*   Updated: 2021/12/10 17:09:33 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>  //need to delete
void		error_input(int *stack_a, int *stack_b);
int			check_max_min(long int a);
long int	atoi_ps(char *str);
int			not_in(int a, int *stack_a, int argc);
int			*pars_values(char **argv, int argc, int *stack_a, int *stack_b);
int			ft_strlen(const char *s);
void		error_input_empty(int *stack_a, int *stack_b);
void		error_input_malloc(int *stack_a, int *stack_b);

void		sa(int **stack_a);
void		sb(int **stack_b);
void		ss(int **stack_a, int **stack_b);
void		ra(int **stack_a, int argc);

#endif