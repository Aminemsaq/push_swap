/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:12:54 by amsaq             #+#    #+#             */
/*   Updated: 2025/03/16 21:16:28 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_push;

	if (!stack_b || !stack_b->top)
		return ;
	node_push = stack_b->top;
	stack_b->top = node_push->next;
	node_push->next = stack_a->top;
	stack_a->top = node_push;
	stack_a->size++;
	stack_b->size--;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_push;

	if (!stack_a || !stack_a->top)
		return ;
	node_push = stack_a->top;
	stack_a->top = node_push->next;
	node_push->next = stack_b->top;
	stack_b->top = node_push;
	stack_b->size++;
	stack_a->size--;
	ft_putstr_fd("pb\n", 1);
}
