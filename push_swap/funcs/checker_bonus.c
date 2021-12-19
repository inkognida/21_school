/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:49:23 by hardella          #+#    #+#             */
/*   Updated: 2021/12/19 14:05:44 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ok_ko(int flag, char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (flag == 911)
	{
		write(1, "KO\n", ft_strlen("KO\n"));
		free_stack(stack_a);
		free_stack(stack_b);
		free(cmd);
	}
	if (flag == 1)
	{
		write(1, "OK\n", ft_strlen("OK\n"));
		free_stack(stack_a);
		free_stack(stack_b);
		free(cmd);
	}
	exit(0);
}

int	parse_command(char **cmd)
{
	int	rd;
	int	i;

	i = 0;
	rd = 0;
	rd = read(0, &(*cmd)[i], 1);
	while (rd > 0 && (*cmd)[i] != '\n')
	{
		i++;
		rd = read(0, &(*cmd)[i], 1);
		if (i > 4)
		{
			while (rd > 0 && (*cmd)[0] != '\n')
				rd = read(0, &(*cmd)[0], 1);
			return (0);
		}
	}
	(*cmd)[i] = '\0';
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*r1;
	unsigned char	*r2;
	unsigned int	check;

	r1 = (unsigned char *) s1;
	r2 = (unsigned char *) s2;
	i = 0;
	while ((r1[i] || r2[i]) && i < n)
	{
		if (r1[i] != r2[i])
		{
			check = r1[i] - r2[i];
			return (check);
		}
		i++;
	}
	return (0);
}

void	accept_cmd(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "sa", 2) == 0)
		sa(stack_a, 0);
	else if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "sb", 2) == 0)
		sb(stack_b, 0);
	else if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "ss", 2) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "ra", 2) == 0)
		ra(stack_a, 0);
	else if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "rb", 2) == 0)
		rb(stack_b, 0);
	else if (ft_strlen(cmd) == 3 && ft_strncmp(cmd, "rrr", 3) == 0)
		rrr(stack_a, stack_b, 0);
	else if (ft_strlen(cmd) == 3 && ft_strncmp(cmd, "rra", 3) == 0)
		rra(stack_a, 0);
	else if (ft_strlen(cmd) == 3 && ft_strncmp(cmd, "rrb", 3) == 0)
		rrb(stack_b, 0);
	else if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "rr", 2) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "pa", 2) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "pb", 2) == 0)
		pb(stack_a, stack_b, 0);
	else
		error_bonus(cmd, stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*cmd;

	cmd = (char *)malloc(sizeof(char) * 4);
	if (!cmd)
		exit(1);
	stack_a = NULL;
	stack_b = NULL;
	get_stack(&stack_a, argv, argc);
	while (1)
	{
		if (parse_command(&cmd) == 0)
			error_bonus(cmd, &stack_a, &stack_b);
		if (ft_strlen(cmd) == 0)
			break ;
		accept_cmd(&stack_a, &stack_b, cmd);
	}
	if (check_sort(stack_a) && ft_lstsize(stack_b) == 0)
		ok_ko(1, cmd, &stack_a, &stack_b);
	ok_ko(911, cmd, &stack_a, &stack_b);
}
