/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:40:10 by amsaq             #+#    #+#             */
/*   Updated: 2025/03/17 17:23:35 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	free_atoi(t_data *data)
{
	free_data(data);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

static int	check_long_overflow(long result, int digit, int sign)
{
	if (sign == 1 && (result > LONG_MAX / 10
			|| (result == LONG_MAX / 10 && digit > LONG_MAX % 10)))
		return (1);
	if (sign == -1 && (result < LONG_MIN / 10
			|| (result == LONG_MIN / 10 && digit > -(LONG_MIN % 10))))
		return (1);
	return (0);
}

static int	check_int_overflow(long result)
{
	if (result > INT_MAX || result < INT_MIN)
		return (1);
	return (0);
}

long	ft_atoi(const char *str, t_data *data)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	while (my_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (check_long_overflow(result, str[i] - '0', sign))
			free_atoi(data);
		result = (result * 10) + (sign * (str[i] - '0'));
		i++;
	}
	if (check_int_overflow(result))
		free_atoi(data);
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
