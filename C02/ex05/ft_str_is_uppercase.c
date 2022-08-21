/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:01:23 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/02 21:29:38 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	is_all_upper;
	int	i;

	if (str[0] == '\0')
		is_all_upper = 1;
	else
	{
		i = 0;
		is_all_upper = 1;
		while (str[i] != '\0')
		{
			if (str[i] < 'A' || str[i] > 'Z')
			{
				is_all_upper = 0;
				break ;
			}
			i++;
		}
	}
	return (is_all_upper);
}
