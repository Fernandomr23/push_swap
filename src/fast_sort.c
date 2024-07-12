/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:39:40 by fmorenil          #+#    #+#             */
/*   Updated: 2024/06/05 13:23:33 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack_node **a)
{
	t_stack_node	*high;

	high = ft_lsthigh(*a);
	if ((*a) == high)
		ra(a, false);
	else if ((*a)->next == high)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	sort_5(t_stack_node **a, t_stack_node **b)
{
	while (ft_lstsize(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, ft_lstsmall(*a), 'a');
		pb(a, b, false);
	}
}

void	fast_sort(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = ft_lstsize((*a));
	if (size == 2)
		sa(a, false);
	else if (size == 3)
		sort_3(a);
	else
		sort_5(a, b);
}
