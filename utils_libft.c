/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:24:48 by amsaq             #+#    #+#             */
/*   Updated: 2025/03/16 21:37:37 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(const char *s1)
{
	int		len_s1;
	char	*result;
	int		i;

	len_s1 = ft_strlen(s1);
	result = (char *)malloc((len_s1 + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
