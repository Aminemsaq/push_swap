/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:12:36 by amsaq             #+#    #+#             */
/*   Updated: 2025/03/16 21:12:37 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data)
{
	data->numbers_int = NULL;
	data->long_number = NULL;
	data->long_split = NULL;
	data->size = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	if (ac == 1)
		return (0);
	if (joining(ac, av, &data) == 0)
		return (free_data(&data), 0);
	if (!ft_parsing(&data))
	{
		return (free_data(&data), 0);
	}
	init_push_swap(data);
	free_data(&data);
	return (0);
}
