/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:57:26 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/02 21:29:12 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	is_all_lower;
	int	i;

	if (str[0] == '\0')
		is_all_lower = 1;
	else
	{
		i = 0;
		is_all_lower = 1;
		while (str[i] != '\0')
		{
			if (str[i] < 'a' || str[i] > 'z')
			{
				is_all_lower = 0;
				break ;
			}
			i++;
		}
	}
	return (is_all_lower);
}
