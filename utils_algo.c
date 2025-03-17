/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:19:25 by amsaq             #+#    #+#             */
/*   Updated: 2025/03/16 21:22:04 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value)
		sa(stack);
}

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->top->value;
	b = stack->top->next->value;
	c = stack->top->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}	
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

int	find_min_index(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		min_pos;
	int		i;

	current = stack->top;
	min = current->index_sorted;
	min_pos = 0;
	i = 0;
	while (current)
	{
		if (current->index_sorted < min)
		{
			min = current->index_sorted;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

void	move_to_top(t_stack *stack, int min_index)
{
	int	size;

	size = stack->size;
	if (min_index <= size / 2)
	{
		while (min_index-- > 0)
			ra(stack);
	}
	else
	{
		min_index = size - min_index;
		while (min_index-- > 0)
			rra(stack);
	}
}

void	sort_four_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;
	int	size;

	size = stack_a->size;
	index_stack_sorted(stack_a);
	index_stack(stack_a);
	while (size > 3)
	{
		min_index = find_min_index(stack_a);
		move_to_top(stack_a, min_index);
		pb(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
	{
		pa(stack_a, stack_b);
	}
}
