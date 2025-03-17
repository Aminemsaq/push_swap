/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:18:11 by amsaq             #+#    #+#             */
/*   Updated: 2025/03/16 21:18:12 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_node	*top_node;
	t_node	*second_node;
	t_node	*current;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	top_node = stack->top;
	second_node = top_node->next;
	stack->top = second_node;
	top_node->next = NULL;
	current = stack->top;
	while (current->next)
		current = current->next;
	current->next = top_node;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack)
{
	t_node	*top_node;
	t_node	*second_node;
	t_node	*current;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	top_node = stack->top;
	second_node = top_node->next;
	stack->top = second_node;
	top_node->next = NULL;
	current = stack->top;
	while (current->next)
		current = current->next;
	current->next = top_node;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_putstr_fd("rr\n", 1);
}
