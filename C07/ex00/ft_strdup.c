/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:36:40 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/08 22:38:35 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	int		len;
	int		i;

	len = 0;
	while (src[len] != '\0')
		len++;
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < len)
		copy[i] = src[i];
	copy[i] = '\0';
	return (copy);
}
