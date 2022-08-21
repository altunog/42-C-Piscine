/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:00:50 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/09 13:29:33 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stocks;
	int			s_idx;

	stocks = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stocks)
		return (NULL);
	s_idx = 0;
	while (s_idx < ac)
	{
		stocks[s_idx].size = ft_strlen(av[s_idx]);
		stocks[s_idx].str = av[s_idx];
		stocks[s_idx].copy = ft_strdup(av[s_idx]);
		s_idx++;
	}
	stocks[s_idx].size = 0;
	stocks[s_idx].str = 0;
	stocks[s_idx].copy = 0;
	return (stocks);
}
