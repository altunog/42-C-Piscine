/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:57:21 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/03 07:35:09 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	validate(char *base)
{
	int	i;
	int	j;
	int	b_len;

	i = 0;
	b_len = ft_strlen(base);
	if (base[0] == '\0' || b_len == 1)
		return (0);
	while (i < b_len - 1)
	{
		if (base[i] <= 32 || base[i] == 127 || base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (j < b_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_parse(char *str)
{
	int	i;
	int	minus;

	minus = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	return (minus * i);
}

int	get_base_index(char n, char *base)
{
	int	i;

	i = -1;
	while (base[++i] != '\0')
		if (n == base[i])
			return (i);
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	i;
	int	minus;
	int	result;
	int	digit_loc;

	if (!validate(base))
		return (0);
	base_len = ft_strlen(base);
	minus = 1;
	i = ft_parse(str); 
	if (i < 0)
	{
		minus = -1;
		i *= -1;
	}
	result = 0;
	digit_loc = get_base_index(str[i], base);
	while (digit_loc != -1)
	{
		result = result * base_len + (get_base_index(str[i], base));
		digit_loc = get_base_index(str[++i], base);
	}
	return (result * minus);
}
#include <stdio.h>
int		main(void)
{
	printf("%d\n", ft_atoi_base("	+++++--133742", "0123456789"));
	printf("%d\n", ft_atoi_base("	     ---101010", "01"));
	printf("%d\n", ft_atoi_base(" 	+---539", "0123456789abcdef"));
}
