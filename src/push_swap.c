/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:56:16 by fmorenil          #+#    #+#             */
/*   Updated: 2024/06/05 13:32:03 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b, false);
	node_current_position(*a);
	node_current_position(*b);
}

static void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b, false);
	node_current_position(*a);
	node_current_position(*b);
}

void	finish_rotation(t_stack_node **stack, t_stack_node *head,
char stack_name)
{
	while (*stack != head)
	{
		if (stack_name == 'a')
		{
			if (head->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (head->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = ft_cheapest(*b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		reverse_rotate_both(a, b, cheapest);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target_node, 'a');
	pa(a, b, false);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int				size;
	t_stack_node	*smallest;

	size = ft_lstsize(*a);
	if (size <= 5)
		sort_5(a, b);
	else
	{
		while (size-- > 3)
			pb(a, b, false);
	}
	sort_3(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	node_current_position(*a);
	smallest = ft_lstsmall(*a);
	if (smallest->above_median)
		while (smallest != *a)
			ra(a, false);
	else
		while (smallest != *a)
			rra(a, false);
}
