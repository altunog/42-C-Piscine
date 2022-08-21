/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaltun <oaltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:20:22 by oaltun            #+#    #+#             */
/*   Updated: 2022/08/03 09:22:11 by oaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap_with_next(char **av, int i)
{
	char	*tmp;

	tmp = av[i];
	av[i] = av[i + 1];
	av[i + 1] = tmp;
}

void	ft_sort_ascending(int ac, char **av)
{
	int		i;
	int		j;

	while (ac > 1)
	{
		i = 1;
		while (i < ac - 1)
		{
			j = 0;
			while (av[i][j] != '\0' || av[i + 1][j] != '\0')
			{
				if (av[i][j] != av[i + 1][j])
					break ;
				j++;
			}
			if (av[i][j] > av[i + 1][j])
				ft_swap_with_next(av, i);
			i++;
		}
		ac--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 1)
		ft_sort_ascending(argc, argv);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
