/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:40:40 by amsaq             #+#    #+#             */
/*   Updated: 2025/03/16 21:40:56 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isvalid(char c)
{
	if (((c >= '0' && c <= '9') || c == '\t'))
		return (1);
	return (0);
}

int	is_valid_number(char *number)
{
	int	j;
	int	sign_t;

	j = 0;
	sign_t = 0;
	if ((number[0] == '+' || number[0] == '-') && !number[1])
		return (ft_putstr_fd("Error\n", 2), 0);
	while (number[j] == '-' || number[j] == '+')
	{
		if (++sign_t > 1)
			return (ft_putstr_fd("Error\n", 2), 0);
		j++;
	}
	while (number[j])
	{
		if (!ft_isvalid(number[j]))
			return (ft_putstr_fd("Error\n", 2), 0);
		j++;
	}
	return (1);
}

int	ft_parsing(t_data *data)
{
	int	i;

	i = 0;
	while (data->long_split[i])
	{
		if (!is_valid_number(data->long_split[i]))
			return (0);
		i++;
	}
	if (convert_to_int(data) == 0)
		return (0);
	if (data->numbers_int == NULL)
		return (0);
	if (!check_dupl(data->numbers_int, i))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (check_sorted(data->numbers_int, i))
	{
		return (0);
	}
	data->size = i;
	return (1);
}

int	check_dupl(int *numbers_int, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers_int[i] == numbers_int[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_sorted(int *numbers_int, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers_int[i] > numbers_int[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
