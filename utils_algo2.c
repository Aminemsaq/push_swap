/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:22:44 by amsaq             #+#    #+#             */
/*   Updated: 2025/03/16 21:23:18 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	t_node	*head;
	int		max;
	int		max_bits;

	head = stack->top;
	max = head->index_sorted;
	max_bits = 0;
	while (head)
	{
		if (head->index_sorted > max)
			max = head->index_sorted;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_radix(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = stack_a->top;
	size = stack_a->size;
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = stack_a->top;
			if (((head_a->index_sorted >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (stack_b->size != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
