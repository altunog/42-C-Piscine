/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:42:11 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/08 22:42:29 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	range = (int *)malloc((max - min) * sizeof(int));
	if (!range)
		return (NULL);
	i = 0;
	while (min + i < max)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = ft_range(min, max);
	if (!*range)
		return (-1);
	return (max - min);
}
