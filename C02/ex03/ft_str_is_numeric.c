/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:49:05 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/02 21:28:37 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	is_numeric;
	int	i;

	if (str[0] == '\0')
		is_numeric = 1;
	else
	{
		i = 0;
		is_numeric = 1;
		while (str[i] != '\0')
		{
			if (str[i] < '0' || str[i] > '9')
			{	
				is_numeric = 0;
				break ;
			}
			i++;
		}
	}
	return (is_numeric);
}
