/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:09:14 by fmorenil          #+#    #+#             */
/*   Updated: 2024/06/05 14:01:46 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_current_position(t_stack_node *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (!stack)
		return ;
	middle = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= middle)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	node_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_index;

	while (b)
	{
		best_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_index)
			{
				best_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_index == LONG_MAX)
			b->target_node = ft_lstsmall(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	node_price(t_stack_node *a, t_stack_node *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = size_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += size_a - (b->target_node->current_position);
		b = b->next;
	}
}

void	node_cheapest(t_stack_node *b)
{
	long			best_value;
	t_stack_node	*cheapest;

	if (!b)
		return ;
	best_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_value)
		{
			best_value = b->push_price;
			cheapest = b;
		}
		b = b->next;
	}
	cheapest->cheapest = true;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	node_current_position(a);
	node_current_position(b);
	node_target_node(a, b);
	node_price(a, b);
	node_cheapest(b);
}
