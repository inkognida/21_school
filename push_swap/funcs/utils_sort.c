/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:38:21 by hardella          #+#    #+#             */
/*   Updated: 2021/12/20 11:12:10 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	get_index(t_stack **stack_a, int elem)
{
	t_stack	*tmp;
	int		index;

	index = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->num == elem)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (index);
}

int	get_min(t_stack	**stack_a)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack_a;
	min = tmp->num;
	while (tmp)
	{
		if (min >= tmp->num)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (get_index(stack_a, min));
}

int	get_max(t_stack	**stack_a)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack_a;
	max = tmp->num;
	while (tmp)
	{
		if (max <= tmp->num)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (get_index(stack_a, max));
}

int	get_max_elem(t_stack	**stack_a)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack_a;
	max = tmp->num;
	while (tmp)
	{
		if (max < tmp->num)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min_elem(t_stack	**stack_a)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack_a;
	min = tmp->num;
	while (tmp)
	{
		if (min > tmp->num)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}
