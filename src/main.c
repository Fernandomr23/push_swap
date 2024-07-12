/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:30:07 by fmorenil          #+#    #+#             */
/*   Updated: 2024/06/12 13:34:48 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	start_stack(t_stack_node **a, char **argv, bool check_argc_2)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		to_the_stack(a, (int)num);
		i++;
	}
	if (check_argc_2)
		ft_free(argv);
}

static void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = ft_lstsize((*a));
	if (ft_lstsize(*a) <= 3)
		fast_sort(a, b);
	else
		push_swap(a, b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	if (argc < 2)
		return (1);
	check_args(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		start_stack(&stack_a, argv, true);
	}
	else
		start_stack(&stack_a, argv + 1, false);
	if (!is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
