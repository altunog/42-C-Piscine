/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:00:27 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/03 07:28:00 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	while (base[i] != '\0')
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

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	lnbr;

	if (!validate(base))
		return ;
	base_len = ft_strlen(base);
	lnbr = nbr;
	if (lnbr < 0)
	{
		write(1, "-", 1);
		lnbr *= -1;
	}
	if (lnbr >= 0 && lnbr <= base_len - 1)
		write(1, &base[lnbr], 1);
	if (lnbr >= base_len)
	{
		ft_putnbr_base(lnbr / base_len, base);
		ft_putnbr_base(lnbr % base_len, base);
	}
}
