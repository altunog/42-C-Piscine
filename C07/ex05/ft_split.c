/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:02:24 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/09 12:01:51 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	check_if_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != 0)
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_till_sep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !check_if_sep(str[i], charset))
		i++;
	return (i);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	word_count;

	word_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] && check_if_sep(str[i], charset))
			i++;
		if (str[i] && !check_if_sep(str[i], charset))
			word_count++;
		while (str[i] && !check_if_sep(str[i], charset))
			i++;
	}
	return (word_count);
}

char	*get_word(char *str, char *charset)
{
	char		*word;
	int			word_len;
	int			seat;

	word_len = ft_strlen_till_sep(str, charset);
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	seat = -1;
	while (++seat < word_len)
		word[seat] = *(str + seat);
	word[seat] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**wordlist;
	int		word_count;
	int		spot;

	word_count = count_words(str, charset);
	wordlist = (char **)malloc(sizeof(char *) * word_count + 1);
	if (!wordlist)
		return (0);
	spot = 0;
	while (spot < word_count)
	{
		while (*str && check_if_sep(*str, charset))
			str++;
		if (*str)
		{
			wordlist[spot] = get_word(str, charset);
			spot++;
		}
		while (*str && !check_if_sep(*str, charset))
			str++;
	}
	wordlist[spot] = 0;
	return (wordlist);
}

int main()
{
	char **wl;
	int	i = 0;

	wl = ft_split("   hello...from. .    .mars,nerede,tr-erdoha_nnn!    ", ".,-!");

	while (wl[i] != 0)
	{
		printf("%s\n", wl[i]);
		i++;
	}
}
