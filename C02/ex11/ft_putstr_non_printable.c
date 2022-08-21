/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:42:13 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/02 21:38:14 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_convert_to_hex(unsigned char c)
{
	char	*hex;
	char	back_slash;

	hex = "0123456789abcdef";
	back_slash = '\\';
	write(1, &back_slash, 1);
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	unsigned char	c;

	i = 0;
	c = str[i];
	while (c != '\0')
	{
		if (c < 32)
			ft_convert_to_hex(c);
		else
			write(1, &c, 1);
		i++;
		c = str[i];
	}
}
