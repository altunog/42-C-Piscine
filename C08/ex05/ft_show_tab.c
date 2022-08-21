/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:04:18 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/09 11:04:21 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
		write(1, &str[i], 1);
}

void	ft_putnbr(int num)
{
	char	n;

	n = '0';
	if (num == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_putnbr(147483648);
	}
	else if (num < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-num);
	}
	else if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else if (num < 10)
	{	
		n += num;
		write(1, &n, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	s_idx;

	s_idx = 0;
	while (par[s_idx].str != 0)
	{
		ft_putstr(par[s_idx].str);
		ft_putstr("\n");
		ft_putnbr(par[s_idx].size);
		ft_putstr("\n");
		ft_putstr(par[s_idx].copy);
		ft_putstr("\n");
		s_idx++;
	}
}
