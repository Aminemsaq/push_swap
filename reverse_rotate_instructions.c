/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:17:58 by amsaq             #+#    #+#             */
/*   Updated: 2025/03/16 21:17:59 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	t_node	*prev;
	t_node	*current;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	prev = NULL;
	current = stack->top;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	if (prev)
		prev->next = NULL;
	current->next = stack->top;
	stack->top = current;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack)
{
	t_node	*prev;
	t_node	*current;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	prev = NULL;
	current = stack->top;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	if (prev)
		prev->next = NULL;
	current->next = stack->top;
	stack->top = current;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
