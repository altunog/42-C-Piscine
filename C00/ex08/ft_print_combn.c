/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:44:04 by oaltun            #+#    #+#             */
/*   Updated: 2022/07/26 12:16:06 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_get_status(int n, int *var)
{
	int	r_i;
	int	end_value;

	r_i = n - 1;
	end_value = 10 - n + r_i;
	while (var[r_i] == end_value && r_i >= 0)
	{
		r_i--;
		end_value = 10 - n + r_i;
	}
	return (r_i--);
}

void	ft_print(int n, int *var)
{
	char	digit;
	int		i;

	i = 0;
	while (i < n)
	{
		digit = '0' + var[i];
		write(1, &digit, 1);
		i++;
	}
	if (ft_get_status(n, var) != -1)
		write(1, ", ", 2);
}

char	ft_set_values(int n, int *var)
{
	int		ch_index;
	char	success;

	ch_index = ft_get_status(n, var);
	if (ch_index >= 0)
	{
		success = 'T';
		var[ch_index] += 1;
		while ((ch_index + 1) <= (n - 1))
		{
			var[ch_index + 1] = var[ch_index] + 1;
			ch_index++;
		}
	}
	else
		success = 'F';
	return (success);
}

void	ft_increment(int n, int *var)
{
	while (var[n - 1] <= 9)
	{
		ft_print(n, var);
		if (var[n - 1] == 9)
			break ;
		var[n - 1] += 1;
	}
	if (ft_set_values(n, var) == 'T')
		ft_increment(n, var);
}

void	ft_print_combn(int n)
{
	int	var[9];
	int	i;

	if (n > 0 && n < 10)
	{
		i = 0;
		while (i < n)
		{
			var[i] = i;
			i++;
		}
		ft_increment(n, var);
	}
	else
		return ;
}
