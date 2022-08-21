/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:54:10 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/02 23:42:19 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == 0)
		return (str);
	while (str[i] != 0)
	{
		j = 0;
		if (to_find[j] == str[i])
		{
			while (to_find[j] != 0 && to_find[j] == str[i + j])
				j++;
		}
		if (to_find[j] == 0)
		{
			str += i;
			return (str);
		}
		i++;
	}
	return (0);
}
