/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:50:51 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/02 21:28:17 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	is_alpha;
	int	i;

	if (str[0] == '\0')
		is_alpha = 1;
	else
	{
		i = 0;
		while (str[i] != '\0' )
		{
			if ((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z'))
				is_alpha = 1;
			else
			{	
				is_alpha = 0;
				break ;
			}
			i++;
		}
	}
	return (is_alpha);
}
