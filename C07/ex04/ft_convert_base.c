/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 02:32:33 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/10 09:19:29 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);
int	validate(char *base);
int	ft_atoi_base(char *str, char *base);

int	final_digitlen(int inbr, int base_len)
{
	int		ndigits;
	long	linbr;

	ndigits = 0;
	linbr = inbr;
	if (linbr < 0)
	{
		linbr = -linbr;
		ndigits++;
	}	
	while (linbr > base_len)
	{
		ndigits++;
		linbr /= base_len;
	}
	return (ndigits + 1);
}

void	set_digit_base(char *rnbr, int ndigits, int inbr, char *base)
{
	int		base_len;
	long	linbr;
	int		digit_loc;

	base_len = ft_strlen(base);
	linbr = inbr;
	digit_loc = ndigits - 1;
	if (linbr < 0)
	{
		rnbr[0] = '-';
		linbr *= -1;
	}
	while (linbr >= base_len)
	{
		rnbr[digit_loc] = base[linbr % base_len];
		linbr /= base_len;
		digit_loc--;
	}
	if (linbr < base_len)
		rnbr[digit_loc] = base[linbr];
	
	printf("%s\n", rnbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		inbr;
	int		bto_len;
	int		ndigits;
	char	*rnbr;

	if (!validate(base_to) || !validate(base_from))
		return (NULL);
	inbr = ft_atoi_base(nbr, base_from);
	printf("convert_base() inbr = %d\n", inbr);
	bto_len = ft_strlen(base_to);
	ndigits = final_digitlen(inbr, bto_len);
	rnbr = malloc(sizeof(char) * (ndigits + 1));
	if (!rnbr)
		return (NULL);
	printf("final digit len = %d\n", ndigits);
	set_digit_base(rnbr, ndigits, inbr, base_to);
	rnbr[ndigits] = '\0';
	return (rnbr);
}
int main ()
{
	printf("%s\n", ft_convert_base("80000000", "0123456789abcdef", "0123456789"));
//	printf("%s\n", ft_convert_base("  +-+-+-7fffffff", "0123456789abcdef", "0123456789"));
}
