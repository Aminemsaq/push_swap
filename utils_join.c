/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:33:10 by amsaq             #+#    #+#             */
/*   Updated: 2025/03/16 23:11:58 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	joining(int ac, char **av, t_data *data)
{
	int		i;
	char	*temp;

	i = 1;
	while (i < ac)
	{
		if (help_join(av[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		temp = ft_strjoin(data->long_number, av[i]);
		free(data->long_number);
		data->long_number = temp;
		if (i < ac - 1)
		{
			temp = ft_strjoin(data->long_number, " ");
			free(data->long_number);
			data->long_number = temp;
		}
		i++;
	}
	data->long_split = ft_split(data->long_number, ' ');
	return (1);
}

int	help_join(char *number)
{
	char	*str;

	str = ft_strtrim(number);
	if (!str)
		return (0);
	if (str[0] == '\0')
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
		return ;
	if (data->long_split)
	{
		while (data->long_split[i])
		{
			free(data->long_split[i]);
			i++;
		}
		free(data->long_split);
	}
	if (data->long_number)
		free(data->long_number);
	if (data->numbers_int)
		free(data->numbers_int);
	data->numbers_int = NULL;
	data->long_number = NULL;
	data->long_split = NULL;
	data->size = 0;
}
