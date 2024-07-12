/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:30:44 by fmorenil          #+#    #+#             */
/*   Updated: 2024/06/12 15:09:17 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(long tmp, char **args, int i)
{
	i++;
	while (args[i])
	{
		if (ft_atoi(args[i]) == tmp)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_check_errors(char **args, int i, bool check_args)
{
	long	tmp;

	while (args[i])
	{
		tmp = ft_atol(args[i]);
		if (!ft_isnum(args[i]) || ft_contains(tmp, args, i)
			|| (tmp < -2147483648 || tmp > 2147483647))
		{
			if (check_args)
				ft_free(args);
			ft_error();
		}
		i++;
	}
	if (check_args)
		ft_free(args);
}

void	check_args(int argc, char **argv)
{
	int		i;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	if (args == NULL)
		ft_error();
	ft_check_errors(args, i, argc == 2);
}
