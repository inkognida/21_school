/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:51:52 by hardella          #+#    #+#             */
/*   Updated: 2021/12/13 17:51:15 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	find_median(int *nums, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (nums[j] > nums[j + 1])
			{
				tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	if (len % 2 == 0)
		return (((nums[len / 2] + nums[len / 2 - 1]) / 2));
	else
		return (nums[len / 2]);
}

void	get_two_stacks(t_stack **stack_a, t_stack **stack_b, int median, int l)
{
	int	i;

	i = 0;
	while (i < l + 1)
	{	
		if ((*stack_a)->num >= median)
		{
			pb(stack_a, stack_b, 1);
			i++;
		}
		else
			ra(stack_a, 1);
	}
}

void	sort_one(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		*nums;
	int		i;
	int		l;

	tmp = *stack_a;
	l = ft_lstsize(*stack_a);
	nums = (int *)malloc(sizeof(int) * l);
	if (!nums)
		return ;
	i = 0;
	while (tmp)
	{
		nums[i++] = tmp->num;
		tmp = tmp->next;
	}
	get_two_stacks(stack_a, stack_b, find_median(nums, l), l / 2);
}
