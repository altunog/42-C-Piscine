/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:03:10 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/02 21:30:29 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	is_printable;
	int	i;

	if (str[0] == '\0')
		is_printable = 1;
	else
	{
		i = 0;
		is_printable = 1;
		while (str[i] != '\0')
		{
			if (str[i] < 32)
			{
				is_printable = 0;
				break ;
			}
			i++;
		}
	}
	return (is_printable);
}
