/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:05:51 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/10 11:05:35 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_strsepcat(char *dst, char *src, char *sep, int is_full)
{
	unsigned int	i;
	unsigned int	last;

	last = ft_strlen(dst);
	printf("strsepcat() last = %i\n", last);
	printf("strsepcat() is null = %d\n", dst[last] == 0);

	i = 0;
	while (src[i] != '\0')
	{
		dst[last] = src[i];
		i++;
		last++;
	}
	if (!is_full)
	{
		i = 0;
		while (sep[i] != '\0')
		{
			dst[last] = sep[i];
			i++;
			last++;
		}
	}
	dst[last] = '\0';
	return (dst);
}

int	ft_full_length(int size, char **strs, int sep_len)
{
	unsigned int	full_len;
	int				i;

	full_len = 0;
	i = 0;
	while (i < size)
	{
		full_len += ft_strlen(strs[i]);
		full_len += sep_len;
		i++;
	}
	full_len -= sep_len;
	return (full_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*alls;
	int		full_len;
	int		sep_len;
	int		i;
	int		last_word;

	sep_len = ft_strlen(sep);
	full_len = ft_full_length(size, strs, sep_len);
	alls = (char *)malloc(sizeof(char) * (full_len + 1));
	if (!alls)
		return (0);
	last_word = 0;
	i = 0;
	while (i < size)
	{
		if (i == size - 1)
			last_word = 1;
		ft_strsepcat(alls, strs[i], sep, last_word);
		i++;
	}
	return (alls);
}
int main()
{
	char	**strs;
	char	*separator;
	char	*result;
	int	size;
	size = 3;
	strs = (char **)malloc(3 * sizeof(char *));
	strs[0] = (char *)malloc(sizeof(char) * 5 + 1);
	strs[1] = (char *)malloc(sizeof(char) * 7 + 1);
	strs[2] = (char *)malloc(sizeof(char) * 14 + 1);
	strs[0] = "Hello";
	strs[1] = "";
	strs[2] = "you are awesome";
	separator = ",";
	result = ft_strjoin(size, strs, separator);
	printf("%s$\n", result);
	free(result);
}

