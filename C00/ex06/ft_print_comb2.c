/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:18:25 by oaltun            #+#    #+#             */
/*   Updated: 2022/07/23 15:52:48 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_comb2(int i, int j, char last)
{
	ft_putchar(48 + i / 10);
	ft_putchar(48 + i % 10);
	ft_putchar(' ');
	ft_putchar(48 + j / 10);
	ft_putchar(48 + j % 10);
	if (last == 'F')
	{	
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	last;

	i = 0;
	last = 'F';
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			if (i == 98 && j == 99)
				last = 'T';
			ft_write_comb2(i, j, last);
			j++;
		}
		i++;
	}
}
