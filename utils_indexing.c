/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_indexing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:32:27 by amsaq             #+#    #+#             */
/*   Updated: 2025/03/16 21:32:28 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *stack)
{
	int		i;
	int		*arr;
	t_node	*current;

	i = 0;
	if (!stack || stack->size == 0)
		return (NULL);
	arr = malloc(stack->size * sizeof(int));
	if (!arr)
		return (NULL);
	current = stack->top;
	while (i < stack->size)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	return (arr);
}

void	bubble_sort(int *arr, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	get_sorted_indices(t_stack *stack, int *sorted_values)
{
	t_node	*current;
	int		i;

	current = stack->top;
	while (current)
	{
		i = 0;
		while (i < stack->size)
		{
			if (current->value == sorted_values[i])
			{
				current->index_sorted = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	index_stack_sorted(t_stack *stack)
{
	int	*sorted_values;

	if (!stack || stack->size == 0)
		return ;
	sorted_values = stack_to_array(stack);
	if (!sorted_values)
		return ;
	bubble_sort(sorted_values, stack->size);
	get_sorted_indices(stack, sorted_values);
	free(sorted_values);
}

void	index_stack(t_stack *stack)
{
	int		i;
	t_node	*current;

	if (!stack || stack->size == 0)
		return ;
	i = 0;
	current = stack->top;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
}
